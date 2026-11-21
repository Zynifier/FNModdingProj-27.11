// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "FortMovementComp_CharacterSubsystem.generated.h"

class UFortMovementControls;
class UFortMovementMode_ExtRegistry;

UCLASS(MinimalAPI)
class UFortMovementComp_CharacterSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FGameplayTag, TObjectPtr<UFortMovementControls>> MovementControlsMap;

	UPROPERTY(Transient)
	TObjectPtr<UFortMovementMode_ExtRegistry> FortMovementMode_Registry;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, MinimalAPI)
class UFortMovementControls : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Movement Controls")
	FGameplayTag MovementControlsTag;

};

