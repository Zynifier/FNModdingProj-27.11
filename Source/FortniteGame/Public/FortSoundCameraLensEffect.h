// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortEmitterCameraLensEffectDirectional.h"
#include "FortSoundCameraLensEffect.generated.h"

class AActor;
class UTexture;
enum class EFortSoundIndicatorTypes : uint8;

UENUM(BlueprintType)
enum class EFortSoundIndicatorTypes : uint8
{
	Generic = 0,
	FootStep = 1,
	Gunshot = 2,
	Chest = 3,
	Glider = 4,
	Vehicle = 5,
	Infected = 6,
	Healing = 7,
	COUNT = 8,
};

USTRUCT(BlueprintType)
struct FSoundIndicatorInitializationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoundIndicatorInitializationData")
	FName EmitterName;

	UPROPERTY(EditAnywhere, Category="SoundIndicatorInitializationData")
	FVector Offset;

	UPROPERTY(EditAnywhere, Category="SoundIndicatorInitializationData")
	float Lifetime;

};

UCLASS(HideCategories=("Activation", "Components|Activation", "Input", "Collision", "Game|Damage"))
class AFortSoundCameraLensEffect : public AFortEmitterCameraLensEffectDirectional
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	UTexture* GetDefaultIcon();

	UFUNCTION(BlueprintImplementableEvent)
	FLinearColor GetDefaultTint();

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	FRuntimeFloatCurve GetStrengthCurveForActiveType() const;

	UFUNCTION(BlueprintCallable)
	void SetIcon(UTexture* NewIcon);

	UFUNCTION(BlueprintCallable)
	void SetIconOverride(UTexture* NewIcon);

	UFUNCTION(BlueprintCallable)
	void SetInstigatingActor(const AActor* NewInstigator);

	UFUNCTION(BlueprintCallable)
	void SetStrengthCurve(const FRuntimeFloatCurve& Curve);

	UFUNCTION(BlueprintCallable)
	void SetTintOverride(FLinearColor Color);

	UFUNCTION(BlueprintCallable)
	void SetType(EFortSoundIndicatorTypes NewType);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	EFortSoundIndicatorTypes IndicatorType;

	UPROPERTY(EditAnywhere, Category="Effects")
	int32 SnapToSections;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	float MaxAudibleDistanceOnSpawn;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<AActor> InstigatingActor;

protected:
	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<UTexture> IconOverride;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	FLinearColor TintOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TMap<EFortSoundIndicatorTypes, FSoundIndicatorInitializationData> EmitterDataMap;

};

