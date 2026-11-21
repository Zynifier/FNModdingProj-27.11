// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/MidiSongPos.h"
#include "FabricModulatorInterface.generated.h"

class UFabricMetaSoundModulatorPatchWrapper;
class UFabricModulatable;
class UObject;
class UPlaylistUserOptionBase;
enum class EFabricUserOptionType : uint8;

UENUM(BlueprintType)
enum class EFabricUserOptionType : uint8
{
	Boolean = 0,
	Integer = 1,
	Float = 2,
	String = 3,
	Enum = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFloatProviderConnectionChanged, bool, bConnected, UObject*, ModulatorObject);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnModulatedPropertyValueChanged, FString, Value, UObject*, ModulatorObject);

UINTERFACE()
class FABRICRUNTIME_API UFabricModulator : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricModulator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	UFabricMetaSoundModulatorPatchWrapper* GetConnectedModulatorPatchWrapper() const;

	UFUNCTION(BlueprintNativeEvent)
	bool GetIsModulating() const;

	UFUNCTION(BlueprintNativeEvent)
	FString GetModulatedProperty();

	UFUNCTION(BlueprintNativeEvent)
	UPlaylistUserOptionBase* GetModulatedUserOption() const;

	UFUNCTION(BlueprintNativeEvent)
	bool GetModulatedValueBool(const FMidiSongPos& SongPos) const;

	UFUNCTION(BlueprintNativeEvent)
	uint8 GetModulatedValueEnum(const FMidiSongPos& SongPos) const;

	UFUNCTION(BlueprintNativeEvent)
	float GetModulatedValueFloat(const FMidiSongPos& SongPos) const;

	UFUNCTION(BlueprintNativeEvent)
	int32 GetModulatedValueInt(const FMidiSongPos& SongPos) const;

	UFUNCTION(BlueprintNativeEvent)
	FString GetModulatedValueString(const FMidiSongPos& SongPos) const;

	UFUNCTION(BlueprintNativeEvent)
	EFabricUserOptionType GetModulatorType() const;

};

UINTERFACE()
class FABRICRUNTIME_API UFabricModulatorDevice : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricModulatorDevice
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void SetUserOption(EFabricUserOptionType UserOptionType, UPlaylistUserOptionBase* UserOption, UObject* ModulatorObject);

};

UINTERFACE()
class FABRICRUNTIME_API UFabricModulatorSource : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricModulatorSource
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void GetModulators(UFabricModulatable* Modulatable);

	UFUNCTION(BlueprintNativeEvent)
	UPlaylistUserOptionBase* GetUserOption(const FString& Property) const;

};

