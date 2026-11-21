// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlaylistUserOptions.h"
#include "PlaylistUserOptionScript.generated.h"

class UVerseCreativeDevice;

USTRUCT(BlueprintType)
struct FPlaylistOptionScriptValue : public FPlaylistOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistOptionScriptValue")
	TSubclassOf<UVerseCreativeDevice> Value;

};

UCLASS(BlueprintType)
class UPlaylistUserOptionScript : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, Transient, Category="PlaylistUserOptionScript")
	TArray<FPlaylistOptionScriptValue> OptionValues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionScript")
	int32 DefaultValueIndex;

};

