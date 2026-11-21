// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Color.h"
#include "FortPropertyOverrideData.h"
#include "FortTimeOfDayManager.h"
#include "FortVolumeTimeOfDayComponent.generated.h"

class AActor;
class AFortPlayerControllerSpectating;
class AFortPlayerState;
class AInfo;
class IFortTimeOfDayManagerInterface;
class UDaySequence;
class UDaySequenceModifierComponent;
class UObject;
class UPostProcessComponent;

USTRUCT()
struct FFortVolumeDaySequenceModifierData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FTimeOfDayDirectOverrides Overrides;

	UPROPERTY(Transient)
	float TimeOfDay;

	UPROPERTY(Transient)
	float TimeOfDaySpeed;

};

USTRUCT()
struct FFortVolumeTimeOfDayConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	uint8 bShouldOverrideTimeOfDay : 1;

	UPROPERTY(Transient)
	uint8 bUseRandomTimeOfDay : 1;

};

UCLASS(Config=Game, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortVolumeTimeOfDayComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ApplyInhibitorFogOverrides(float FogDensity, FLinearColor FogColor);

	UFUNCTION(BlueprintCallable)
	void ApplyTimeOfDayComponentSettings(bool bShouldSwitch = true);

	UFUNCTION(BlueprintCallable)
	static TScriptInterface<IFortTimeOfDayManagerInterface> GetTimeOfDayManager(AActor* TimeOfDayComponentOwner);

	UFUNCTION(BlueprintPure)
	TScriptInterface<IFortTimeOfDayManagerInterface> GetVolumeTimeOfDayManager() const;

	UFUNCTION(BlueprintCallable)
	void SwitchToGlobalTODManager();

	UFUNCTION(BlueprintCallable)
	void SwitchToLocalTODManager();

	UFUNCTION(BlueprintCallable)
	static TScriptInterface<IFortTimeOfDayManagerInterface> TryGetTimeOfDayManager(AActor* TimeOfDayComponentOwner);

protected:
	UPROPERTY(EditAnywhere, Category="FortVolumeTimeOfDayComponent")
	bool bUseEditorOverrideData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(ClampMax="24.000000", ClampMin="0.000000", EditCondition="bUseEditorOverrideData"))
	float TimeOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bUseEditorOverrideData"))
	float SpeedOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bUseEditorOverrideData", InlineEditConditionToggle))
	bool bOverrideLightIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bOverrideLightIntensity"))
	float LightIntensityOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bUseEditorOverrideData", InlineEditConditionToggle))
	bool bOverrideLightColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bOverrideLightColor"))
	FLinearColor LightColorOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bUseEditorOverrideData", InlineEditConditionToggle))
	bool bOverrideFogDensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bOverrideFogDensity"))
	float FogDensityOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bUseEditorOverrideData", InlineEditConditionToggle))
	bool bOverrideFogColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bOverrideFogColor"))
	FLinearColor FogColorOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bUseEditorOverrideData", InlineEditConditionToggle))
	bool bOverridePostProcess;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortVolumeTimeOfDayComponent", meta=(EditCondition="bOverridePostProcess"))
	TSubclassOf<UObject> PostProcessOverride;

	UPROPERTY(EditAnywhere, Config, Category="FortVolumeTimeOfDayComponent", meta=(MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TSoftClassPtr<AInfo> OverrideTODClass;

	UPROPERTY(EditAnywhere, Config, Category="FortVolumeTimeOfDayComponent")
	bool bSplitscreenUseOverrideTODClass;

	UPROPERTY(EditAnywhere, Category="FortVolumeTimeOfDayComponent")
	TObjectPtr<UDaySequence> DaySequenceOverride;

	UPROPERTY(EditAnywhere, Config, Category="FortVolumeTimeOfDayComponent")
	bool bDirectlyTrackLocalViewTarget;

	UPROPERTY(EditAnywhere, Config, Category="FortVolumeTimeOfDayComponent")
	bool bDirectlyTrackLocalCameraPosition;

	UPROPERTY(EditAnywhere, Config, Category="FortVolumeTimeOfDayComponent", meta=(ClampMin="0"))
	float LocalTrackingTickRate;

	UPROPERTY(EditAnywhere, Config, Category="FortVolumeTimeOfDayComponent", meta=(ClampMin="1"))
	float LocalTrackingOverlapRadius;

private:
	UFUNCTION()
	void CreateLocalTimeOfDayManager();

	UFUNCTION()
	void HandleViewTargetChanged();

	UFUNCTION()
	void MutatorSettingsChanged(const FPropertyOverrideData& OverrideData);

	UFUNCTION()
	void OnRep_DaySequenceModifierData();

	UFUNCTION()
	void OnRep_TimeOfDayConfig();

	UFUNCTION()
	void OnRep_TimeOfDayManager();

	UFUNCTION()
	void SpectatorFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer);

	UFUNCTION()
	void UpdateLocalTracking();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TimeOfDayManager)
	TScriptInterface<IFortTimeOfDayManagerInterface> TimeOfDayManager;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TimeOfDayConfig)
	FFortVolumeTimeOfDayConfig TimeOfDayConfig;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DaySequenceModifierData)
	FFortVolumeDaySequenceModifierData DaySequenceModifierData;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UDaySequenceModifierComponent> DaySequenceModifierComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPostProcessComponent> OverridePostProcessComponent;

	UPROPERTY(Transient)
	bool bIsOverridingTimeOfDay;

};

