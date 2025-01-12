// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryData/InventoryStucts.h"
#include "BaseInventoryComponent.generated.h"

//**************************************************************************************************
//* this is called so that you can hook up save functionality on the fly								   *
//* I do not recommend saving to slot every time, just updating it in your save game object        *
//* then set up save on end play and on any time the screen darkens,										   *
//* ie sleep/opening menus/ entering new scenes																		*
//**************************************************************************************************

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryUpdated, TMap<FGuid, FItemInventoryStruct>, InventoryToSave);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VORPISINVENTORYCOMPONENTMODULE_API UBaseInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	// delegate
	UPROPERTY(BlueprintAssignable)
	FInventoryUpdated OnInventoryUpdated;

public:	
	// Sets default values for this component's properties
	UBaseInventoryComponent();

	// base data
	TMap<FGuid, FItemInventoryStruct> InventoryMap;

	// inventory functions
	UFUNCTION(BlueprintPure)
	FItemInventoryStruct GetItemData(FGuid ItemGuid) { return InventoryMap[ItemGuid]; }
	UFUNCTION(BlueprintCallable)
	void AddItem(FItemInventoryStruct ItemData) { InventoryMap.Add(ItemData.ItemData.ItemGuid, ItemData); }

	UFUNCTION(BlueprintCallable)
	void AddItemToInventory(FItemInventoryStruct ItemData);
	UFUNCTION(BlueprintCallable)
	void UpdateItemInInventory(FItemInventoryStruct ItemData);
	UFUNCTION(BlueprintCallable)
	void RemoveItemFromInventory(FGuid ItemGuid);
	UFUNCTION(BlueprintCallable)
	void ClearInventory();
	UFUNCTION(BlueprintCallable)
	void SortStackableItems();

	// inventory space 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Spacec", Meta = (ExposeOnSpawn = true))
	FInventorySpaceStruct InventorySpace;


	// save and load
	UFUNCTION(BlueprintCallable)
	void InitializeInventory(TMap<FGuid, FItemInventoryStruct> InventoryData, FInventorySpaceStruct CurrentSpace);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
