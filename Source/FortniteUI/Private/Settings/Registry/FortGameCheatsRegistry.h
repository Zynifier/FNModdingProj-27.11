// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/Registry/FortSettingRegistry.h"
#include "FortGameCheatsRegistry.generated.h"

USTRUCT()
struct FCheatMenuEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString DevName;

	UPROPERTY()
	FString DisplayName;

	UPROPERTY()
	FString RichText;

	UPROPERTY()
	TArray<FString> ConsoleCommands;

};

USTRUCT()
struct FCheatMenuSection
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString DevName;

	UPROPERTY()
	FString DisplayName;

	UPROPERTY()
	FString MinVersion;

	UPROPERTY()
	TArray<FCheatMenuEntry> Entries;

	UPROPERTY()
	bool bExpanded;

};

UCLASS(Config=CheatsRegistry)
class UFortGameCheatsRegistry : public UFortSettingRegistry
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<FCheatMenuSection> SeasonalSections;

	UPROPERTY()
	TArray<FCheatMenuSection> AdminSections;

	UPROPERTY(Config)
	TArray<FCheatMenuEntry> LastUsedEntries;

};

