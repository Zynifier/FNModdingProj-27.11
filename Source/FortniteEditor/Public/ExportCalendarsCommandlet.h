// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "ExportCalendarsCommandlet.generated.h"

USTRUCT()
struct FCalendarEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Decl;

	UPROPERTY()
	FString SortBy;

	UPROPERTY()
	FString SortBy2;

};

USTRUCT()
struct FExportAllCalendarData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 NumCalendars;

	UPROPERTY()
	int32 NumProcessed;

	UPROPERTY()
	bool bExportSuccessful;

};

UCLASS()
class UExportCalendarsCommandlet : public UCommandlet
{
	GENERATED_BODY()

};

