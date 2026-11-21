// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyLoop_AbductionWarning.generated.h"

class AActor;
class UAudioComponent;
class UFXSystemComponent;
class UNiagaraComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(DisplayName="GCNL Abduction Warning", ShowWorldContextPin))
class AFortGameplayCueNotifyLoop_AbductionWarning : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Niagara FX")
	float MaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="Niagara FX")
	FName VariableName;

	UPROPERTY(EditDefaultsOnly, Category="Niagara FX")
	FName PlayerSocket;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_AbductionWarning")
	TObjectPtr<AActor> TargetActor;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortGameplayCueNotifyLoop_AbductionWarning", meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> WarningFXSystemComponent;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortGameplayCueNotifyLoop_AbductionWarning", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> WarningFXNiagaraComponent;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_AbductionWarning")
	FVector WarningFXOriginLocation;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortGameplayCueNotifyLoop_AbductionWarning", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> WarningAudioComponent;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_AbductionWarning")
	TObjectPtr<AActor> RadialForceLoop;

};

