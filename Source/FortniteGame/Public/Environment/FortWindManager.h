// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Environment/FortWindImpulse.h"
#include "Environment/FortWindResponder.h"
#include "FortInitializationInterface.h"
#include "FortWindManager.generated.h"

class ABuildingSMActor;
class AFortWindManager;
class UAudioComponent;
class UMaterialInterface;
class UObject;
class UParticleSystemComponent;

USTRUCT()
struct FFortWindIntensityAndDirection
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortWindIntensityAndDirection", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0.0"))
	float WindIntensity;

	UPROPERTY(EditDefaultsOnly, Category="FortWindIntensityAndDirection", meta=(ClampMax="360.0", ClampMin="0", UIMax="360.0", UIMin="0.0"))
	float WindHeading;

};

USTRUCT()
struct FFortGlobalWindInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortGlobalWindInfo")
	TArray<FFortWindIntensityAndDirection> ValidWindInfos;

	UPROPERTY(Transient)
	int32 WindIndex;

};

UCLASS(BlueprintType, Blueprintable)
class AFortWindManager : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Wind")
	FFortWindImpulseHandle AddWindImpulse(const FFortWindImpulseRadius& WindImpulse);

	UFUNCTION(BlueprintCallable, Category="Wind")
	FFortWindImpulseHandle AddWindImpulseCylinder(const FFortWindImpulseCylinder& WindImpulseCylinder, float BlendTime);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Wind")
	void AddWindParticleSystemComponent(UParticleSystemComponent* ParticleSystemComponent);

	UFUNCTION(BlueprintPure, Category="Wind", meta=(NativeBreakFunc))
	static void BreakWindImpulseCylinder(const FFortWindImpulseCylinder& InWindImpulseCylinder, FVector& ImpulseLocation, float& ImpulseInnerRadius, float& ImpulseOuterRadius, float& ImpulseMagnitude, FVector& ImpulseDirection);

	UFUNCTION(BlueprintCallable, Category="Wind", meta=(AdvancedDisplay="1"))
	static void BreakWindImpulseCylinderAdvanced(const FFortWindImpulseCylinder& WindImpulseCylinder, FVector& WindLocation, float& WindInnerRadius, float& WindOuterRadius, FVector& WindWorldDirection, float& WindMagnitude, FBox& WindWorldBounds, bool& bIsWindChanging, bool& bIsWindChangePending);

	UFUNCTION(BlueprintCallable, Category="Wind", meta=(AdvancedDisplay="1"))
	static void BreakWindImpulseCylinderDelta(const FFortWindImpulseCylinderDelta& WindImpulseCylinderDelta, FVector& WindDeltaCenter, bool& bWindImpulseInitialized, bool& bWindRipplesOutward, float& WindDeltaSectionWidth, float& WindDeltaInnerSectionRadius, float& WindDeltaOuterSectionRadius, float& WindDeltaMaximumRadius, float& WindDeltaDesiredOverallBlendTime, float& WindDeltaSectionBlendTime, float& WindDeltaSectionCurrentBlendTime, float& WindDeltaPreviousMagnitude, float& WindDeltaSectionCurrentMagnitude, float& WindDeltaDesiredMagnitude, FBox& WindDeltaOuterWorldBounds, FBox& WindDeltaInnerWorldBounds, FBox& WindImpulseBounds, FFortWindImpulseHandle& WindImpulseHandleToModify);

	UFUNCTION(BlueprintPure, Category="Wind", meta=(NativeBreakFunc))
	static void BreakWindImpulseRadius(const FFortWindImpulseRadius& InWindImpulseRadius, FVector& ImpulseLocation, float& ImpulseRadius, float& ImpulseMagnitude, float& ImpulseBlendTime);

	UFUNCTION(BlueprintPure, Category="Wind")
	bool GetCurrentWindImpulseCylinderDelta(FFortWindImpulseCylinder& WindImpulseCylinder, FFortWindImpulseCylinderDelta& WindImpulseCylinderDelta) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Wind")
	void GetGlobalWindIntensityAndDirection(float& WindIntensity, FVector& WindDirection) const;

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static AFortWindManager* GetWindManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Wind")
	bool HasWindImpulse(const FFortWindImpulseHandle& WindImpulseHandle) const;

	UFUNCTION(BlueprintPure, Category="Wind", meta=(Keywords="construct build", NativeMakeFunc))
	static FFortWindImpulseCylinder MakeWindImpulseCylinder(const FVector& ImpulseLocation, float ImpulseInnerRadius, float ImpulseOuterRadius, float ImpulseMagnitude, const FVector& ImpulseDirection);

	UFUNCTION(BlueprintPure, Category="Wind", meta=(Keywords="construct build", NativeMakeFunc))
	static FFortWindImpulseRadius MakeWindImpulseRadius(const FVector& ImpulseLocation, float ImpulseRadius, float ImpulseMagnitude, float ImpulseBlendTime);

	UFUNCTION(BlueprintImplementableEvent, Category="Wind")
	void OnWindImpulseCylinderCreation(const FFortWindImpulseCylinder& WindImpulseCylinder, const FFortWindImpulseCylinderDelta& WindImpulseCylinderDelta);

	UFUNCTION(BlueprintImplementableEvent, Category="Wind")
	void OnWindImpulseCylinderDeath(const FFortWindImpulseCylinder& WindImpulseCylinder);

	UFUNCTION(BlueprintImplementableEvent, Category="Wind")
	void OnWindImpulseCylinderDeltaComplete(const FFortWindImpulseCylinder& WindImpulseCylinder);

	UFUNCTION(BlueprintImplementableEvent, Category="Wind")
	void OnWorldReady();

	UFUNCTION(BlueprintCallable, Category="Wind")
	void RemoveWindImpulse(const FFortWindImpulseHandle& ImpulseHandle, float BlendTime);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Wind")
	void RemoveWindParticleSystemComponent(UParticleSystemComponent* ParticleSystemComponent);

	UFUNCTION(BlueprintCallable, Category="Wind")
	bool SetWindImpulse(const FFortWindImpulseHandle& ImpulseHandle, const FFortWindImpulseRadius& WindImpulse);

	UFUNCTION(BlueprintCallable, Category="Wind")
	bool SetWindImpulseCylinderMagnitude(const FFortWindImpulseHandle& ImpulseHandle, float NewMagnitude, float BlendTime);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Wind")
	void OnWindAudioBecameActive(UAudioComponent* WindAudioComp);

	UFUNCTION(BlueprintImplementableEvent, Category="Wind")
	void OnWindAudioBecameInactive(UAudioComponent* WindAudioComp);

private:
	UPROPERTY(Transient)
	bool bAllowWindImpulses;

	UPROPERTY(Transient)
	bool bAllowResponderAudio;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	float SectionWidth;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	float MinimumSectionBlendTime;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	TSoftObjectPtr<UMaterialInterface> MaterialDefiningParametersToInterpolate;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	FName WindVectorParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	TArray<FName> WindOffsetMaterialParameterNames;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	TArray<FName> WindSpeedMaterialParameterNames;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	TArray<FName> WindMaterialScalarParameterNamesToInterpolate;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	TArray<FName> WindMaterialVectorParameterNamesToInterpolate;

	UPROPERTY(Transient)
	TArray<FFortWindImpulseRadius> WindImpulses;

	UPROPERTY(Transient)
	TArray<FFortWindImpulseCylinderDelta> WindImpulseCylinderDeltas;

	UPROPERTY(Transient)
	TArray<FFortWindImpulseCylinder> WindImpulseCylinders;

	UPROPERTY(Transient)
	TArray<FFortWindResponder> WindResponders;

	UPROPERTY(Transient)
	TArray<int32> NearbyCacheIndicesForAudio;

	UPROPERTY(Transient)
	TArray<int32> NearbyCacheIndicesForUpdates;

	UPROPERTY(Transient)
	int32 NextNearbyIndexToUpdate;

	UPROPERTY(Transient)
	FFortWindResponder ActiveAudioWindResponder;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<TObjectPtr<ABuildingSMActor>, TObjectPtr<UAudioComponent>> WindActorToWindResponderAudioMap;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FName AudioWindSpeedParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float AudioWindInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float AudioWindMaxResponderDistance;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	float UpdateWindMaxResponderDistance;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	float ViewerMovementDistanceForRefresh;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAudioComponent>> WindAudioComponentPool;

};

