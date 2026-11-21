// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "FortCurieNativeFXHandler.generated.h"

class UFortCurieNativeFXHandler;
class UFortCurieNativeFXHandlerConfig;
class USoundBase;

USTRUCT()
struct FFortCurieNativeFXHandlerEntry : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCurieNativeFXHandlerEntry")
	bool bIsActive;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieNativeFXHandlerEntry")
	TSubclassOf<UFortCurieNativeFXHandler> FXHandlerType;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieNativeFXHandlerEntry")
	TObjectPtr<UFortCurieNativeFXHandlerConfig> Config;

};

UCLASS(Abstract, MinimalAPI)
class UFortCurieNativeFXHandler : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortCurieNativeFXHandlerConfig> CachedConfig;

};

UCLASS(Abstract, MinimalAPI)
class UFortCurieNativeFXHandlerConfig : public UPrimaryDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Category="General", meta=(Patchable))
	FName ConfigName;

	UPROPERTY(EditDefaultsOnly, Category="General", meta=(Categories="Curie.NativeFX", Patchable))
	FGameplayTag ConfigTag;

	UPROPERTY(EditDefaultsOnly, Category="Glow", meta=(Patchable))
	uint8 bUseGlow : 1;

	UPROPERTY(EditDefaultsOnly, Category="General", meta=(Patchable))
	uint8 bNeedsSignificanceTracking : 1;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(Patchable))
	uint8 bNeedsAmbientAudio : 1;

	UPROPERTY(EditDefaultsOnly, Category="Glow", meta=(EditCondition="bUseGlow", Patchable))
	int32 GlowPriority;

	UPROPERTY(EditDefaultsOnly, Category="Glow", meta=(EditCondition="bUseGlow", Patchable))
	float GlowMaterialIdx;

	UPROPERTY(EditAnywhere, Category="Glow", meta=(DisplayName="Glow Fade-In Curve", EditCondition="bUseGlow", XAxisName="Time", YAxisName="Alpha Mult"))
	FRuntimeFloatCurve GlowFadeInCurve;

	UPROPERTY(EditAnywhere, Category="Glow", meta=(DisplayName="Glow Fade-Out Curve", EditCondition="bUseGlow", XAxisName="Time", YAxisName="Alpha Mult"))
	FRuntimeFloatCurve GlowFadeOutCurve;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(EditCondition="bNeedsAmbientAudio"))
	TObjectPtr<USoundBase> AmbientSound;

};

