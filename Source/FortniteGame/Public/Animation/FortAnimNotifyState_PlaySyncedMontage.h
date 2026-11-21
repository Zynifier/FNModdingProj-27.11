// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortCustomPartTypeEnum.h"
#include "FortAnimNotifyState_PlaySyncedMontage.generated.h"

class UAnimMontage;

UENUM(BlueprintType)
enum class EMontageSyncTargetType : uint8
{
	Pet = 0,
	CustomPartType = 1,
	Weapon = 2,
};

USTRUCT(BlueprintType)
struct FSyncedMontageParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SyncedMontageParams")
	TObjectPtr<UAnimMontage> SyncedMontage;

	UPROPERTY(EditAnywhere, Category="SyncedMontageParams")
	EMontageSyncTargetType MontageTarget;

	UPROPERTY(EditAnywhere, Category="EditCondition", meta=(EditCondition="MontageTarget == EMontageSyncTargetType::CustomPartType"))
	TEnumAsByte<EFortCustomPartType::Type> PartType;

	UPROPERTY(EditAnywhere, Category="SyncedMontageParams")
	float MontageStopBlendTime;

	UPROPERTY(EditAnywhere, Category="SyncedMontageParams")
	bool bSyncMontage;

};

UCLASS(HideCategories=("Object"), meta=(DisplayName="Play Synced Montage"))
class UFortAnimNotifyState_PlaySyncedMontage : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_PlaySyncedMontage")
	TArray<FSyncedMontageParams> MontageParamsList;

};

