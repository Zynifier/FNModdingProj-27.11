// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyLoop_Sliding.generated.h"

class AFortPlayerPawn;
class UFortLayeredAudioComponent;

USTRUCT()
struct FSlidingAudioParamData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SlidingAudioParamData")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="SlidingAudioParamData")
	FVector2D InRange;

	UPROPERTY(EditDefaultsOnly, Category="SlidingAudioParamData")
	FVector2D OutRange;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(DisplayName="GCNL Sliding", ShowWorldContextPin))
class AFortGameplayCueNotifyLoop_Sliding : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_Sliding")
	bool bCanUpdateParameters;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_Sliding")
	FSlidingAudioParamData VelocityParam;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_Sliding")
	FSlidingAudioParamData SpeedlineVelocityParam;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_Sliding")
	FSlidingAudioParamData WaterImmersionParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortGameplayCueNotifyLoop_Sliding", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> LayeredAudioComp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortGameplayCueNotifyLoop_Sliding")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

};

