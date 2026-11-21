// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "ExportTemplatesCommandlet.generated.h"

USTRUCT()
struct FItemFileRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TemplateId;

	UPROPERTY()
	int32 Quantity;

};

USTRUCT()
struct FInventoryFileRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString MigrationId;

	UPROPERTY()
	TArray<FItemFileRecord> Items;

};

USTRUCT()
struct FInventoryFile
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Migrations;

	UPROPERTY()
	FInventoryFileRecord Inventory;

};

UCLASS()
class UExportTemplatesCommandlet : public UCommandlet
{
	GENERATED_BODY()

};

