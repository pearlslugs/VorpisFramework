// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/BaseInventoryComponent.h"

UBaseInventoryComponent::UBaseInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


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
	FInventorySpaceStruct CurrentSpace,
	FGuid OwnerGuid
)
{
	InventoryMap = InventoryData;
	InventorySpace = CurrentSpace;
	InventoryGuid = OwnerGuid;

	FInventorySaveStruct InventorySaveStruct;
	InventorySaveStruct.InventoryMap = InventoryMap;
	InventorySaveStruct.InventoryGuid = InventoryGuid;
	// this is to force a new save state, in normal
	// game play, it wont do anything
	// but you can call this function directly to force your inventory in your file
	OnInventoryUpdated.Broadcast(InventorySaveStruct);
}

void UBaseInventoryComponent::AddItemToInventory(FItemInventoryStruct ItemData)
{
	EItemRejectionReason RejectionReason = InventorySpace.AddItemsToInventory(
		ItemData.ItemData.ItemAsset->ItemHeight,
		ItemData.ItemData.ItemAsset->ItemWidth
	);
	if (RejectionReason == EItemRejectionReason::EIRR_None) {
		InventoryMap.Add(ItemData.ItemData.ItemGuid, ItemData);
		FInventorySaveStruct InventorySaveStruct;
		InventorySaveStruct.InventoryMap = InventoryMap;
		InventorySaveStruct.InventoryGuid = InventoryGuid;
		OnInventoryUpdated.Broadcast(InventorySaveStruct);
	} else {
		// make a toast widget
		// handle rejection
	}
}
void UBaseInventoryComponent::UpdateItemInInventory(FItemInventoryStruct ItemData)
{
	InventoryMap[ItemData.ItemData.ItemGuid] = ItemData;
	FInventorySaveStruct InventorySaveStruct;
	InventorySaveStruct.InventoryMap = InventoryMap;
	InventorySaveStruct.InventoryGuid = InventoryGuid;
	OnInventoryUpdated.Broadcast(InventorySaveStruct);
}
void UBaseInventoryComponent::RemoveItemFromInventory(FGuid ItemGuid)
{
	FItemData ItemData = InventoryMap[ItemGuid].ItemData;
	InventorySpace.RemoveItemsFromInventory(ItemData.ItemAsset->ItemHeight, ItemData.ItemAsset->ItemWidth);
	InventoryMap.Remove(ItemGuid);

	FInventorySaveStruct InventorySaveStruct;
	InventorySaveStruct.InventoryMap = InventoryMap;
	InventorySaveStruct.InventoryGuid = InventoryGuid;
	OnInventoryUpdated.Broadcast(InventorySaveStruct);
}
void UBaseInventoryComponent::ClearInventory()
{
	InventoryMap.Empty();
	InventorySpace.ResetInventorySpace();
	
	FInventorySaveStruct InventorySaveStruct;
	InventorySaveStruct.InventoryMap = InventoryMap;
	InventorySaveStruct.InventoryGuid = InventoryGuid;
	OnInventoryUpdated.Broadcast(InventorySaveStruct);
}
void UBaseInventoryComponent::SortStackableItems()
{
	// see if this is slow, if so, make a new map of itemasset guid and then asses it by looking up the itemasset. this will make two loops instead of
	// a loop for every item
	for (auto& Item : InventoryMap) {
		for (auto& Item2 : InventoryMap) {
			if (Item.Value.ItemData.ItemAsset->AssetGuid == Item2.Value.ItemData.ItemAsset->AssetGuid) {
				if (Item.Value.ItemCount < Item.Value.ItemData.ItemAsset->MaxStackSize) {
					int RemainingSpace = Item.Value.ItemData.ItemAsset->MaxStackSize - Item.Value.ItemCount;
					if (Item2.Value.ItemCount <= RemainingSpace) {
						Item.Value.ItemCount += Item2.Value.ItemCount;
						InventoryMap.Remove(Item2.Key);
					} else {
						Item2.Value.ItemCount -= RemainingSpace;
						Item.Value.ItemCount += RemainingSpace;
					}
				}
			}
		}
	}
	FInventorySaveStruct InventorySaveStruct;
	InventorySaveStruct.InventoryMap = InventoryMap;
	InventorySaveStruct.InventoryGuid = InventoryGuid;
	OnInventoryUpdated.Broadcast(InventorySaveStruct);
}
