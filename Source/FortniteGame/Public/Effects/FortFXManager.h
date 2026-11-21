// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortClientOnlyActor.h"
#include "FortFXManager.generated.h"

class AActor;
class AFortPickupEffect;
class AFortWeaponRanged;
class UCurveFloat;
class UCurveLinearColor;
class ULightComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
class UParticleSystemComponent;
class UPrimitiveComponent;
class USplineComponent;
class USplineMeshComponent;

USTRUCT()
struct FFortFXAnimationInfoBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<UCurveFloat> LerpCurve;

};

USTRUCT()
struct FFortFloatAnimationInfo : public FFortFXAnimationInfoBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortFloatParamAnimationInfo : public FFortFloatAnimationInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortLightAnimSet
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export)
	TWeakObjectPtr<ULightComponent> LightComp;

	UPROPERTY(Transient)
	TArray<FFortFloatAnimationInfo> IntensityAnims;

};

USTRUCT()
struct FFortLinearColorAnimationInfo : public FFortFXAnimationInfoBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortLinearColorCurveAnimationInfo : public FFortFXAnimationInfoBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortLinearColorCurveParamAnimationInfo : public FFortLinearColorCurveAnimationInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortLinearColorParamAnimationInfo : public FFortLinearColorAnimationInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortMIDAnimSet
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<UMaterialInstanceDynamic> MID;

	UPROPERTY(Transient)
	TArray<FFortFloatParamAnimationInfo> FloatParamAnims;

	UPROPERTY(Transient)
	TArray<FFortLinearColorParamAnimationInfo> ColorParamAnims;

	UPROPERTY(Transient)
	TArray<FFortLinearColorCurveParamAnimationInfo> ColorCurveParamAnims;

};

USTRUCT()
struct FFortParticleAnimSet
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UParticleSystemComponent> PSC;

	UPROPERTY(Transient)
	TArray<FFortFloatParamAnimationInfo> ParamAnims;

};

USTRUCT()
struct FFortSplineMeshScaleAnimationInfo : public FFortFXAnimationInfoBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortSplineMeshSnapAnimationInfo : public FFortFXAnimationInfoBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export)
	TWeakObjectPtr<USplineComponent> TargetSpline;

};

USTRUCT()
struct FFortSplineMeshAnimSet
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export)
	TWeakObjectPtr<USplineMeshComponent> SplineMesh;

	UPROPERTY(Transient)
	TArray<FFortSplineMeshScaleAnimationInfo> ScaleAnims;

	UPROPERTY(Transient)
	TArray<FFortSplineMeshSnapAnimationInfo> SnapAnims;

};

UCLASS(BlueprintType, Blueprintable)
class AFortFXManager : public AFortClientOnlyActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void AddLightAnimationIntensity(UObject* WorldContextObject, ULightComponent* LightComp, float StartValue, float EndValue, UCurveFloat* LerpCurve, bool bOneMinusLerpValue, float Duration, bool bPlayReverse);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void AddMIDAnimationColor(UObject* WorldContextObject, UMaterialInstanceDynamic* MID, FName ParamName, const FLinearColor& StartValue, const FLinearColor& EndValue, UCurveFloat* LerpCurve, bool bOneMinusLerpValue, float Duration, bool bPlayReverse);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void AddMIDAnimationColorCurve(UObject* WorldContextObject, UMaterialInstanceDynamic* MID, FName ParamName, UCurveLinearColor* ColorCurve, float Duration, bool bPlayReverse);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void AddMIDAnimationFloat(UObject* WorldContextObject, UMaterialInstanceDynamic* MID, FName ParamName, float StartValue, float EndValue, UCurveFloat* LerpCurve, bool bOneMinusLerpValue, float Duration, bool bPlayReverse);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void AddParticleAnimationFloat(UObject* WorldContextObject, UParticleSystemComponent* ParticleSystemComp, FName ParamName, float StartValue, float EndValue, UCurveFloat* LerpCurve, bool bOneMinusLerpValue, float Duration, bool bPlayReverse);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void AddSplineMeshScaleAnimation(UObject* WorldContextObject, USplineMeshComponent* SplineMesh, float StartScaleStart, float StartScaleEnd, float EndScaleStart, float EndScaleEnd, UCurveFloat* LerpCurve, bool bOneMinusLerpValue, float Duration, bool bPlayReverse);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void AddSplineMeshSnapAnimation(UObject* WorldContextObject, const TArray<USplineMeshComponent*>& SplineMeshes, USplineComponent* TargetSpline, UCurveFloat* GrowthCurve, float Duration, bool bPlayGrowthReverse);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="PickupObject"))
	static UMaterialInstanceDynamic* GetPickupRarityMID(AFortPickupEffect* PickupObject, UPrimitiveComponent* Component, int32 ElementIndex, int32 Rarity, bool& bNeedsToBeInitialized);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="PickupObject"))
	static UMaterialInstanceDynamic* GetPickupStretchMIDFromPool(AFortPickupEffect* PickupObject, UMaterialInterface* SourceMaterial, UPrimitiveComponent* Component, int32 ElementIndex, bool& bNeedsToBeInitialized);

	UFUNCTION()
	void OnPendingWeaponFXEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void RemoveLightAnimations(UObject* WorldContextObject, ULightComponent* LightComp);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void RemoveMIDAnimations(UObject* WorldContextObject, UMaterialInstanceDynamic* MID);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void RemoveParticleAnimations(UObject* WorldContextObject, UParticleSystemComponent* ParticleSystemComp);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void RemoveSplineMeshAnimations(UObject* WorldContextObject, USplineMeshComponent* SplineMesh);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static void ReturnFXActorToPool(UObject* WorldContextObject, AActor* FXActor);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="PickupObject"))
	static void ReturnPickupStretchMIDToPool(AFortPickupEffect* PickupObject, UPrimitiveComponent* Component, int32 ElementIndex);

	UFUNCTION(BlueprintCallable, Category="FortFX", meta=(WorldContext="WorldContextObject"))
	static AActor* SpawnPooledFXActor(UObject* WorldContextObject, TSubclassOf<AActor> FXActorClass, const FTransform& SpawnTransform);

private:
	UPROPERTY(Transient)
	TArray<FFortSplineMeshAnimSet> SplineAnimSets;

	UPROPERTY(Transient)
	TArray<FFortMIDAnimSet> MIDAnimSets;

	UPROPERTY(Transient)
	TArray<FFortParticleAnimSet> ParticleAnimSets;

	UPROPERTY(Transient)
	TArray<FFortLightAnimSet> LightAnimSets;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortWeaponRanged>> PendingWeaponFX;

};

