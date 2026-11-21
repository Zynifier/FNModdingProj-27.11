// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SpecialEventGameUserSettingsControllerComponent.generated.h"

class UFortAsyncAction_SpecialEventGameUserSettingsReady;
class UObject;
class USpecialEventGameUserSettingsControllerComponent;
enum class ESpecialEventGameUserSettingsResult : uint8;

UENUM(BlueprintType)
enum class ESpecialEventGameUserSettingsResult : uint8
{
	Success = 0,
	Failure = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpecialEventGameUserSettingsControllerComponentLoaded, USpecialEventGameUserSettingsControllerComponent*, GameUserSettingsComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpecialEventGameUserSettingsReadyAsyncDelegate, USpecialEventGameUserSettingsControllerComponent*, GameUserSettingsControllerComponent);

UCLASS()
class UFortAsyncAction_SpecialEventGameUserSettingsReady : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_SpecialEventGameUserSettingsReady* SpecialEventGameUserSettingsReadyAsync(const UObject* WorldContextObject);

	UPROPERTY(BlueprintAssignable)
	FSpecialEventGameUserSettingsReadyAsyncDelegate OnReady;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Activation", "AssetUserData", "Collision", "ComponentReplication", "ComponentTick", "Cooking", "Replication", "Tags"))
class USpecialEventGameUserSettingsControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandEnumAsExecs="OutResult"))
	void GetData(ESpecialEventGameUserSettingsResult& OutResult, FString& OutData) const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
	static USpecialEventGameUserSettingsControllerComponent* GetSpecialEventGameUserSettingsControllerComponent(const UObject* WorldContextObject);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void ParseLoadedData(const FString& Data);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void SetData(const FString& Data, const bool bAllowSave = false, const bool bSaveNow = false);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void SetSavingBlocked(const bool bBlocked);

	UFUNCTION(Exec, BlueprintCosmetic)
	void SpecialEventGameUserSettings_ClearData();

	UFUNCTION(Exec, BlueprintCosmetic)
	void SpecialEventGameUserSettings_LogData() const;

	UFUNCTION(Exec, BlueprintCosmetic)
	void SpecialEventGameUserSettings_SetData(const FString& Data);

	UFUNCTION(Exec, BlueprintCosmetic)
	void SpecialEventGameUserSettings_ToggleDebug();

	UPROPERTY(BlueprintAssignable)
	FOnSpecialEventGameUserSettingsControllerComponentLoaded OnLoaded;

protected:
	UPROPERTY(EditDefaultsOnly, Category="SpecialEventGameUserSettingsControllerComponent")
	FString Version;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventGameUserSettingsControllerComponent")
	float MinTimeBetweenSaves;

};

