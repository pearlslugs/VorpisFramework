// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GameModeInterface/GameModeInterface.h"

// Add default functionality here for any IGameModeInterface functions that are not pure virtual.

void IGameModeInterface::InterfaceSaveInventoryData(FInventorySaveStruct InventoryToSave)
{
	//
}
FInventorySaveStruct IGameModeInterface::InterfaceLoadInventoryData(FGuid InventoryGuid)
{
	FInventorySaveStruct InventoryData;
	return InventoryData;
}
void IGameModeInterface::InterfaceSaveNewPickUp(FPickUpData ItemToSave)
{
	//
}
TMap<FGuid, FPickUpData> IGameModeInterface::InterfaceLoadAllPickups();
{
	TMap<FGuid, FPickUpData> PickUpData;
	return PickUpData;
}