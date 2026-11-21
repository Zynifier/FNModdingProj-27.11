// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyLoop_Swinging.generated.h"

class AFortPlayerPawn;
class UFortLayeredAudioComponent;

USTRUCT()
struct FSwingingAudioParamData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SwingingAudioParamData")
	FName Name;

};

USTRUCT()
struct FSwingingAudioParamDataMapRange : public FSwingingAudioParamData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SwingingAudioParamDataMapRange")
	FVector2D InRange;

	UPROPERTY(EditDefaultsOnly, Category="SwingingAudioParamDataMapRange")
	FVector2D OutRange;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(DisplayName="GCNL Swinging", ShowWorldContextPin))
class AFortGameplayCueNotifyLoop_Swinging : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortGameplayCueNotifyLoop_Swinging", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> LayeredAudioComp;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_Swinging")
	FSwingingAudioParamDataMapRange AngleParam;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_Swinging")
	FSwingingAudioParamDataMapRange LengthParam;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_Swinging")
	FSwingingAudioParamDataMapRange SpeedParam;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_Swinging")
	FSwingingAudioParamData AttachedParam;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_Swinging")
	FSwingingAudioParamData SkiddingParam;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_Swinging")
	FSwingingAudioParamDataMapRange WaterImmersionParam;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayCueNotifyLoop_Swinging")
	FGameplayTag SkiddingTag;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortGameplayCueNotifyLoop_Swinging")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_Swinging")
	bool bCanUpdateParameters;

};

