// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGameObject/VorpisSaveGameObject.h"

void UVorpisSaveGameObject::SaveInventoryData(FInventorySaveStruct InventoryToSave)
{
	AllInventories.Add(InventoryToSave.InventoryGuid, InventoryToSave);
}

FInventorySaveStruct UVorpisSaveGameObject::LoadInventoryData(FGuid InventoryGuid)
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

void UVorpisSaveGameObject::SaveNewPickUp(FPickUpData ItemToSave)
{
	AllPickUps.Add(ItemToSave.ItemData.ItemGuid, ItemToSave);
}

TMap<FGuid, FPickUpData> UVorpisSaveGameObject::LoadAllPickups()
{
	return AllPickUps;
}