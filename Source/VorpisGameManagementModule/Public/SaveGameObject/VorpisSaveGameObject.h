// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "InventoryData/InventoryStucts.h"
#include "VorpisSaveGameObject.generated.h"

/**
 * 
 */
UCLASS()
class VORPISGAMEMANAGEMENTMODULE_API UVorpisSaveGameObject : public USaveGame
{
	GENERATED_BODY()

public:
	//_______________________________________________________________________________________________
	// inventory data
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	TMap<FGuid, FInventorySaveStruct> AllInventories;
	UFUNCTION()
	void SaveInventoryData(FInventorySaveStruct InventoryToSave);
	UFUNCTION()
	FInventorySaveStruct LoadInventoryData(FGuid InventoryGuid);

	//_______________________________________________________________________________________________
	// item data
	// 
	// pick ups will be around the map, when they are picked up
	// they should be removed from here
	// this should be used to get a map of items and spawn them in the chosen location
	// when you drop an item, add it to this list
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	TMap<FGuid, FPickUpData> AllPickUps;
	UFUNCTION()
	void SaveNewPickUp(FPickUpData ItemToSave);
	UFUNCTION()
	TMap<FGuid, FPickUpData> LoadAllPickups();

	//_______________________________________________________________________________________________
	// next data  \ 
	
};
