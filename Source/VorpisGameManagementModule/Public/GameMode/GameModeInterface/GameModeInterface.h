// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InventoryData/InventoryStucts.h"
#include "GameModeInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameModeInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VORPISGAMEMANAGEMENTMODULE_API IGameModeInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void InterfaceSaveInventoryData(FInventorySaveStruct InventoryToSave);
	virtual FInventorySaveStruct InterfaceLoadInventoryData(FGuid InventoryGuid);
	virtual void InterfaceSaveNewPickUp(FPickUpData ItemToSave);
	virtual TMap<FGuid, FPickUpData> InterfaceLoadAllPickups();
};
