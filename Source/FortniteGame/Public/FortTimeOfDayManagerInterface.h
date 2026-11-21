// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTimeOfDayManagerInterface.generated.h"

class IFortTimeOfDayManagerInterface;
class UDirectionalLightComponent;
class UExponentialHeightFogComponent;
class UFortTimeOfDayWeatherComponent;
class UObject;
enum class EFortDayPhase : uint8;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FDayNightPhaseChangeBlueprintEventSignature, EFortDayPhase, CurrentDayPhase, EFortDayPhase, PreviousDayPhase, bool, bAtCreation);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDayNightPhaseChangeSignature, EFortDayPhase, CurrentDayPhase, EFortDayPhase, PreviousDayPhase, bool, bAtCreation);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimeOfDayManagerUpdated, TScriptInterface<IFortTimeOfDayManagerInterface>, TimeOfDayManager);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnWeatherComponentSetBlueprintEventSignature, UFortTimeOfDayWeatherComponent*, WeatherComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeatherComponentSetSignature, UFortTimeOfDayWeatherComponent*, WeatherComponent);

UINTERFACE(MinimalAPI, BlueprintType, NotBlueprintable)
class UFortTimeOfDayManagerInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortTimeOfDayManagerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="TimeOfDay")
	virtual void FastForwardToTime(float FastForwardTimeOfDay, float FastForwardSpeed, float RestoreSpeed = -1.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="TimeOfDay")
	virtual void FastForwardToTime_ByDuration(float FastForwardTimeOfDay, float FastForwardDuration, float RestoreSpeed = -1.000000f);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual EFortDayPhase GetCurrentDayPhase() const;

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual float GetDefaultTimeOfDaySpeed() const;

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual UDirectionalLightComponent* GetDirectionalLightComponent() const;

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual UExponentialHeightFogComponent* GetHeightFogComponent() const;

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual EFortDayPhase GetPreviousDayPhase() const;

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual float GetTimeOfDay() const;

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual float GetTimeOfDaySpeed() const;

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual float GetTimePerCycle() const;

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual UFortTimeOfDayWeatherComponent* GetWeatherComponent() const;

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual bool IsVisible() const;

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual void RegisterForDayPhaseChangedEvent(UPARAM(DisplayName="Event") FDayNightPhaseChangeBlueprintEventSignature DelegateSignature, const bool bMakeInitialCall = false);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual void RegisterForWeatherComponentSetEvent(UPARAM(DisplayName="Event") FOnWeatherComponentSetBlueprintEventSignature DelegateSignature);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="TimeOfDay")
	virtual bool SetTimeOfDay(const float InTimeOfDay);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	virtual void SetTimeOfDayManagerVisibility(const bool bVisible);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="TimeOfDay")
	virtual bool SetTimeOfDaySpeed(const float InTimeOfDaySpeed);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="TimeOfDay")
	virtual bool SetTimeOfDaySpeedFactor(const float NewTimeOfDaySpeedFactor, const bool bForceSet = true);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual void UnregisterForDayPhaseChangedEvent(UObject* EventReceiver);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	virtual void UnregisterForWeatherComponentSetEvent(UPARAM(DisplayName="Event") FOnWeatherComponentSetBlueprintEventSignature DelegateSignature);

};

