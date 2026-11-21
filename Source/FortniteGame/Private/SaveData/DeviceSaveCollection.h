// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DeviceSaveCollection.generated.h"

class USaveData;

UCLASS()
class UDeviceSaveCollection : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(Instanced)
	TMap<TSubclassOf<USaveData>, TObjectPtr<USaveData>> Settings;

};

