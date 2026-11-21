// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "AI/FortAITypes.h"
#include "FortAthenaAILODComponent.generated.h"

class AFortPawn;
class IFortAthenaAILODSettings;
class UFortAIDirectorLODAIConfig;
class UFortAthenaAILODSettingsContainer;
class UFortAthenaAILODSettings_AIEvaluator;
class UFortAthenaAILODSettings_CharacterMovement;
class UFortAthenaAILODSettings_FortWeaponRanged;
class UFortAthenaAILODSettings_GenericTickingObject;
class UObject;

UCLASS(Config=Game, MinimalAPI, ClassGroup=("AI"), meta=(BlueprintSpawnableComponent))
class UFortAthenaAILODComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_CurrentFortAILODLevel();

	UPROPERTY(ReplicatedUsing=OnRep_CurrentFortAILODLevel)
	EFortAILODLevel CurrentFortAILODLevel;

	UPROPERTY(Replicated)
	uint8 bCouldBeVisibleToPlayers : 1;

	UPROPERTY()
	TObjectPtr<AFortPawn> CachedFortPawn;

	UPROPERTY()
	TObjectPtr<UFortAthenaAILODSettingsContainer> AILODSettingsContainer;

};

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAILODSettingsContainer : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TMap<TSubclassOf<UObject>, TScriptInterface<IFortAthenaAILODSettings>> ClassToSettings;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	TArray<TSubclassOf<UFortAthenaAILODSettings_AIEvaluator>> LODSettings_AIEvaluators;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	TArray<TSubclassOf<UFortAthenaAILODSettings_CharacterMovement>> LODSettings_CharacterMovement;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	TArray<TSubclassOf<UFortAthenaAILODSettings_FortWeaponRanged>> LODSettings_FortWeaponRanged;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	TArray<TSubclassOf<UFortAthenaAILODSettings_GenericTickingObject>> LODSettings_GenericTickingObject;

	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	TSubclassOf<UFortAIDirectorLODAIConfig> FortAIDirectorLODConfig;

	UPROPERTY(Transient)
	TObjectPtr<UFortAIDirectorLODAIConfig> FortAIDirectorObjectLODConfig;

};

