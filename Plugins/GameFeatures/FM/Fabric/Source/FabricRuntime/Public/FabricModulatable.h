// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HarmonixMidi/MidiSongPos.h"
#include "FabricModulatable.generated.h"

class AActor;
class IFabricModulator;
class UObject;

UCLASS(Abstract, BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricModulatable : public UObject
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	AActor* GetModulatedActor() const;

	UFUNCTION(BlueprintPure)
	bool GetModulatedBool(const FString& Param, const FMidiSongPos& SongPos, bool& OutBool) const;

	UFUNCTION(BlueprintPure)
	bool GetModulatedEnum(const FString& Param, const FMidiSongPos& SongPos, uint8& OutEnum) const;

	UFUNCTION(BlueprintPure)
	bool GetModulatedFloat(const FString& Param, const FMidiSongPos& SongPos, float& OutFloat) const;

	UFUNCTION(BlueprintPure)
	bool GetModulatedInt(const FString& Param, const FMidiSongPos& SongPos, int32& OutInt) const;

	UFUNCTION(BlueprintPure)
	bool GetModulatedString(const FString& Param, const FMidiSongPos& SongPos, FString& OutString) const;

	UFUNCTION(BlueprintPure)
	TScriptInterface<IFabricModulator> GetModulator(const FString& Param) const;

	UFUNCTION(BlueprintPure)
	bool IsParamModulated(const FString& Param) const;

	UFUNCTION()
	void OnAnyOptionUpdated();

	UFUNCTION()
	void OnOptionsLoaded();

private:
	UFUNCTION()
	void OnModulatedPropertyChanged(const FString& Value, UObject* ModulatorObject);

	UFUNCTION()
	void OnModulatorFloatProviderConnectionChanged(bool bConnected, UObject* ModulatorObject);

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> ModulatedActor;

	UPROPERTY(Transient)
	TArray<FString> ModulatorParams;

	UPROPERTY(Transient)
	TMap<FString, TWeakObjectPtr<UObject>> Modulators;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UObject>> ModulatorSources;

};

