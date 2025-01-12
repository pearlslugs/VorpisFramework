// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/BaseInventoryComponent.h"

// Sets default values for this component's properties
UBaseInventoryComponent::UBaseInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBaseInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBaseInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// should only be called after loading from slot 
// unless you want to force a new inventory in the file
void UBaseInventoryComponent::InitializeInventory(
	TMap<FGuid, FItemInventoryStruct> InventoryData, 
	FInventorySpaceStruct CurrentSpace
)
{
	InventoryMap = InventoryData;
	InventorySpace = CurrentSpace;

	// this is to force a new save state, in normal
	// game play, it wont do anything
	// but you can call this function directly to force your inventory in your file
	OnInventoryUpdated.Broadcast(InventoryMap);
}

void UBaseInventoryComponent::AddItemToInventory(FItemInventoryStruct ItemData)
{
	EItemRejectionReason RejectionReason = InventorySpace.AddItemsToInventory(
		ItemData.ItemData.ItemAsset->ItemHeight,
		ItemData.ItemData.ItemAsset->ItemWidth
	);
	if (RejectionReason == EItemRejectionReason::EIRR_None)
	{
		InventoryMap.Add(ItemData.ItemData.ItemGuid, ItemData);
		OnInventoryUpdated.Broadcast(InventoryMap);
	}
	else
	{
		// make a toast widget
		// handle rejection
	}
}
void UBaseInventoryComponent::UpdateItemInInventory(FItemInventoryStruct ItemData)
{
	InventoryMap[ItemData.ItemData.ItemGuid] = ItemData;
	OnInventoryUpdated.Broadcast(InventoryMap);
}
void UBaseInventoryComponent::RemoveItemFromInventory(FGuid ItemGuid)
{
	FItemData ItemData = InventoryMap[ItemGuid].ItemData;
	InventorySpace.RemoveItemsFromInventory(ItemData.ItemAsset->ItemHeight, ItemData.ItemAsset->ItemWidth);
	InventoryMap.Remove(ItemGuid);
	OnInventoryUpdated.Broadcast(InventoryMap);
}
void UBaseInventoryComponent::ClearInventory()
{
	InventoryMap.Empty();
	InventorySpace.ResetInventorySpace();
	OnInventoryUpdated.Broadcast(InventoryMap);
}
void UBaseInventoryComponent::SortStackableItems()
{
	for (auto& Item : InventoryMap)
	{
		for (auto& Item2 : InventoryMap)
		{
			if (Item.Value.ItemData.ItemAsset->AssetGuid == Item2.Value.ItemData.ItemAsset->AssetGuid)
			{
				if (Item.Value.ItemCount < Item.Value.ItemData.ItemAsset->MaxStackSize)
				{
					int RemainingSpace = Item.Value.ItemData.ItemAsset->MaxStackSize - Item.Value.ItemCount;
					if (Item2.Value.ItemCount <= RemainingSpace)
					{
						Item.Value.ItemCount += Item2.Value.ItemCount;
						InventoryMap.Remove(Item2.Key);
					}
					else
					{
						Item2.Value.ItemCount -= RemainingSpace;
						Item.Value.ItemCount += RemainingSpace;
					}
				}
			}
		}
	}
	OnInventoryUpdated.Broadcast(InventoryMap);
}
