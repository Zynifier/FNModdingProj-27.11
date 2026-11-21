// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyAthena_AIAlertState.generated.h"

class AFortPawn;
class AFortPlayerPawn;
class UFortAbilitySystemComponent;
class UFortAthenaAlertStateComponent;
class UStaticMeshComponent;

UCLASS(HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class AFortGameplayCueNotifyAthena_AIAlertState : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTargetDied(AFortPawn* DeadPawn);

private:
	UFUNCTION()
	void AlertStateHideTagCallback(const FGameplayTag Tag, int32 NewCount);

	UFUNCTION()
	void HandleAbilitySystemComponentInitialized(UFortAbilitySystemComponent* AbilitySystemComponent, AFortPlayerPawn* Pawn);

	UFUNCTION()
	void OnTargetDied_Internal(AFortPawn* DeadPawn);

	UFUNCTION()
	void OnTeamChanged(uint8 oldTeam);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortGameplayCueNotifyAthena_AIAlertState", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> SpriteMeshComponent;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyAthena_AIAlertState")
	FName SpriteMeshAttachSocketName;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyAthena_AIAlertState")
	FTransform SpriteMeshRelativeTransform;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyAthena_AIAlertState")
	int32 FillIconDataFloatIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayCueNotifyAthena_AIAlertState", meta=(AllowPrivateAccess="true"))
	float StealthMeterStartValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortGameplayCueNotifyAthena_AIAlertState", meta=(AllowPrivateAccess="true"))
	int32 CurrentGameplayEffectLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortGameplayCueNotifyAthena_AIAlertState", meta=(AllowPrivateAccess="true"))
	float CurrentStealthMeterPctFilled;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaAlertStateComponent> CurrentAlertStateComponent;

};

