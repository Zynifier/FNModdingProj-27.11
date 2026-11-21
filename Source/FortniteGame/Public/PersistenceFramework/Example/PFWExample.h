// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/Example/PFWCheatTestSetup.h"
#include "PersistenceFramework/PersistenceFrameworkSubsystemExtension_SaveControl.h"
#include "PFWExample.generated.h"

class AFortPlayerController;
class UPFWExample_GameObject;

UCLASS()
class FORTNITEGAME_API UPFWExample : public UPFWCheatTestSetup
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FString PersistentName;

	UPROPERTY()
	TObjectPtr<UPFWExample_GameObject> MyGameObject;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> FortPlayerController;

	UPROPERTY()
	FPersistenceFrameworkSaveControl SaveControl;

	UPROPERTY()
	int32 AssignedValue;

};

