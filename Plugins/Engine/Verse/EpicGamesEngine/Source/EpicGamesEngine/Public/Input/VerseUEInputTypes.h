// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "InputCoreTypes.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "VerseUEInputTypes.generated.h"

class UVerseUEInputComponentBase;

USTRUCT()
struct FVerseActionMapping : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Name;

	UPROPERTY()
	FString UIText;

	UPROPERTY()
	TArray<FKey> Keys;

};

USTRUCT()
struct FVerseActionMappingArray : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FVerseActionMapping> ActionMappingArray;

	UPROPERTY(NotReplicated)
	TObjectPtr<UVerseUEInputComponentBase> OwningComponent;

};

USTRUCT()
struct FVerseAxisMapping : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName AxisName;

	UPROPERTY()
	float Scale;

	UPROPERTY()
	FString UIText;

	UPROPERTY()
	TArray<FKey> Keys;

};

USTRUCT()
struct FVerseAxisMappingArray : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FVerseAxisMapping> AxisMappingArray;

	UPROPERTY(NotReplicated)
	TObjectPtr<UVerseUEInputComponentBase> OwningComponent;

};

USTRUCT()
struct FVerseInputBinding : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Name;

	UPROPERTY()
	TEnumAsByte<EInputEvent> InputEvent;

};

USTRUCT()
struct FVerseInputBindingArray : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FVerseInputBinding> InputBindingArray;

	UPROPERTY(NotReplicated)
	TObjectPtr<UVerseUEInputComponentBase> OwningComponent;

};

