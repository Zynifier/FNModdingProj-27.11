// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FabricModulatable.h"
#include "HarmonixMidi/MidiSongPos.h"
#include "FabricFloatProvider.generated.h"

class UFabricFloatProviderBase;
class UFabricMetaSoundModulatorPatchWrapper;
class UMusicClockComponent;
enum class EFabricFloatProviderType : uint8;

UENUM(BlueprintType)
enum class EFabricFloatProviderType : uint8
{
	Continuous = 0,
	// Continuous float providers will message their float every time it changes

	Instantaneous = 1,
};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricFloatProviderBase : public UFabricModulatable
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFloatChanged, float, Float);

public:
	UFUNCTION(BlueprintPure)
	UFabricMetaSoundModulatorPatchWrapper* GetAssociatedPatchWrapper() const;

	UFUNCTION(BlueprintPure)
	virtual float GetCurrentFloat() const;

	UFUNCTION(BlueprintPure)
	float GetFloatAtSongPos(const FMidiSongPos& SongPos) const;

	UFUNCTION(BlueprintPure)
	virtual EFabricFloatProviderType GetFloatProviderType() const;

	UFUNCTION(BlueprintCallable)
	void SetAssociatedPatchWrapper(UFabricMetaSoundModulatorPatchWrapper* PatchWrapper);

	UFUNCTION(BlueprintCallable)
	void SetMusicClock(UMusicClockComponent* NewMusicClock);

	UFUNCTION(BlueprintCallable)
	void SetProviderEnabled(bool bInIsEnabled);

	UPROPERTY(BlueprintAssignable)
	FOnFloatChanged OnFloatChanged;

protected:
	UFUNCTION(BlueprintPure)
	FMidiSongPos GetCurrentSongPos() const;

	UFUNCTION(BlueprintPure)
	FMidiSongPos GetCurrentSongPosWithOffset(float OffsetSeconds) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Tick"))
	void ReceiveTick(float DeltaSeconds);

	UPROPERTY(BlueprintReadWrite, Category="FabricFloatProviderBase")
	float CurrentFloat;

	UPROPERTY(BlueprintReadOnly, Export, Category="FabricFloatProviderBase")
	TWeakObjectPtr<UMusicClockComponent> MusicClock;

	UPROPERTY(BlueprintReadOnly, Category="FabricFloatProviderBase")
	TObjectPtr<UFabricMetaSoundModulatorPatchWrapper> AssociatedPatchWrapper;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderBase")
	FString EnabledParam;

	UPROPERTY(EditDefaultsOnly, Category="FabricFloatProviderBase")
	bool bAlwaysModulates;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricFloatProviderBase")
	bool bBindBlueprintOnFloatChanged;

	UPROPERTY(BlueprintReadOnly, Category="FabricFloatProviderBase")
	bool bIsEnabled;

	UPROPERTY(BlueprintReadOnly, Category="FabricFloatProviderBase")
	bool bModulatorValueChanged;

};

UCLASS(BlueprintType)
class FABRICRUNTIME_API UFabricModulationNode : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<UFabricFloatProviderBase*> FloatProviders;

};

