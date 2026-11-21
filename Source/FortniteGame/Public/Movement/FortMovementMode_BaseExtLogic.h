// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "Movement/FortMovementMode_ExtType.h"
#include "FortMovementMode_BaseExtLogic.generated.h"

class AFortPawn;
class UFortMovementComp_Character;

UENUM(BlueprintType)
enum class EFortMovementModeExt_PhysUpdateResult : uint8
{
	Continue = 0,
	AbortIteration = 1,
	AbortPhysUpdate = 2,
};

USTRUCT()
struct FORTNITEGAME_API FFortMovementMode_BaseExtCreationData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortMovementMode_BaseExtRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FMovementMode_ExtID LogicID;

	UPROPERTY()
	uint8 RuntimeID;

private:
	UPROPERTY()
	bool bForceManualActivation;

	UPROPERTY()
	bool bForceManualEnd;

};

UCLASS()
class FORTNITEGAME_API UFortMovementMode_BaseExtLogic : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnExtensionActivate"))
	void BP_OnExtensionActivate();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnExtensionDeactivate"))
	void BP_OnExtensionDeactivate();

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMovementMode_BaseExtLogic")
	TWeakObjectPtr<AFortPawn> OwnerPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortMovementMode_BaseExtLogic")
	TWeakObjectPtr<UFortMovementComp_Character> OwnerMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMovementMode_BaseExtLogic")
	bool bUseFullSimulation;

	UPROPERTY()
	FMovementMode_ExtID LogicID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMovementMode_BaseExtLogic")
	FGameplayTagContainer MovementModeExtensionIDTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMovementMode_BaseExtLogic")
	FGameplayTagContainer AbilityIDTag;

};

