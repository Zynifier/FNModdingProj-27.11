// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "NiagaraDataChannel_Islands.h"
#include "FortNiagaraDataChannels.generated.h"

class UFXSystemAsset;
class UNiagaraDataChannelAsset;
class UNiagaraDataChannel_Fort;
class USceneComponent;

USTRUCT()
struct FFortNDCImpactInfo_CachedData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UNiagaraDataChannel_Fort> CachedNDC;

};

USTRUCT()
struct FFortNDCImpactInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Effects", meta=(EditCondition="bUseNDCImpacts"))
	TSoftObjectPtr<UNiagaraDataChannelAsset> ImpactFXDataChannel;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(EditCondition="bUseNDCImpacts"))
	TMap<TEnumAsByte<EPhysicalSurface>, TSoftObjectPtr<UNiagaraDataChannelAsset>> PerSurfaceImpactFXDataChannel;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(EditCondition="bUseNDCImpacts"))
	float Damage;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(EditCondition="bUseNDCImpacts"))
	uint8 bSimple : 1;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(DisplayPriority="0"))
	uint8 bUseNDCImpacts : 1;

private:
	UPROPERTY(Transient)
	FFortNDCImpactInfo_CachedData CachedNDCInfo;

	UPROPERTY(Transient)
	TMap<TEnumAsByte<EPhysicalSurface>, FFortNDCImpactInfo_CachedData> PerSurfaceCachedNDCInfo;

};

USTRUCT()
struct FFortNDC_Attached_PerComponentData
{
	GENERATED_BODY()

};

UCLASS()
class UNiagaraDataChannelHandler_Fort : public UNiagaraDataChannelHandler_Islands
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TMap<TWeakObjectPtr<USceneComponent>, FFortNDC_Attached_PerComponentData> PerComponentData;

};

UCLASS()
class UNiagaraDataChannel_Fort : public UNiagaraDataChannel_Islands
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Moving Objects")
	uint8 bHandleMovingObjects : 1;

	UPROPERTY(EditAnywhere, Category="Migration", meta=(InlineEditConditionToggle))
	uint8 bUseFXAllowList : 1;

	UPROPERTY(EditAnywhere, Category="Migration", meta=(InlineEditConditionToggle))
	uint8 bUseFXDenyList : 1;

	UPROPERTY(EditAnywhere, Category="Migration", meta=(editCondition="bUseFXAllowList"))
	TSet<TSoftObjectPtr<UFXSystemAsset>> FXAllowList;

	UPROPERTY(EditAnywhere, Category="Migration", meta=(editCondition="bUseFXDenyList"))
	TSet<TSoftObjectPtr<UFXSystemAsset>> FXDenyList;

	UPROPERTY(EditAnywhere, Category="Moving Objects", meta=(editCondition="bHandleMovingObjects"))
	float MovementBaseBoundsMultiplier;

	UPROPERTY(EditAnywhere, Category="Moving Objects", meta=(editCondition="bHandleMovingObjects"))
	float MovementBaseSpeedThreshold;

};

