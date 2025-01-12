// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveObject/VorpisSaveGame.h"

void UVorpisSaveGame::SaveInventoryData(FInventorySaveStruct InventoryToSave)
{
	AllInventories.Add(InventoryToSave.InventoryGuid, InventoryToSave);
}

FInventorySaveStruct UVorpisSaveGame::LoadInventoryData(FGuid InventoryGuid)
{
	if (AllInventories.Contains(InventoryGuid))
	{
		return AllInventories[InventoryGuid];
	}
	else
	{
		FInventorySaveStruct EmptyInventory;
		return EmptyInventory;
	}
}

void UVorpisSaveGame::SaveNewPickUp(FPickUpData ItemToSave)
{
	AllPickUps.Add(ItemToSave.ItemData.ItemGuid, ItemToSave);
}

TMap<FGuid, FPickUpData> UVorpisSaveGame::LoadAllPickups()
{
	return AllPickUps;
}