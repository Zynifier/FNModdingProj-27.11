// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataRegistry.h"
#include "DataRegistrySource.h"
#include "DataRegistrySource_CurveTable.h"
#include "DataRegistrySource_DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortDataRegistry.generated.h"

class UFortDataRegistrySource_ScopedCurveTable;
class UFortDataRegistrySource_ScopedDataTable;
class UObject;

USTRUCT()
struct FFortOverrideData
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortOverrideData_CurveTableEntry : public FFortOverrideData
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortOverrideData_DataTableEntry : public FFortOverrideData
{
	GENERATED_BODY()

};

UCLASS()
class UFortDataRegistry : public UDataRegistry
{
	GENERATED_BODY()

};

UCLASS(meta=(DisplayName="Scoped CurveTable Source"))
class UFortDataRegistrySource_ScopedCurveTable : public UDataRegistrySource_CurveTable
{
	GENERATED_BODY()

};

UCLASS(meta=(DisplayName="Scoped DataTable Source"))
class UFortDataRegistrySource_ScopedDataTable : public UDataRegistrySource_DataTable
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortDataRegistryUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class UFortMetaDataRegistrySource_MutatorList : public UMetaDataRegistrySource
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="DataRegistry")
	FDataRegistrySource_DataTableRules TableRules;

	UPROPERTY(EditAnywhere, Category="DataRegistry")
	TSubclassOf<UFortDataRegistrySource_ScopedCurveTable> CreatedSourceClass;

};

UCLASS(BlueprintType)
class UFortMetaDataRegistrySource_OverrideData : public UMetaDataRegistrySource
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="DataRegistry")
	FDataRegistrySource_DataTableRules TableRules;

};

UCLASS(BlueprintType)
class UFortMetaDataRegistrySource_OverrideCurveTable : public UFortMetaDataRegistrySource_OverrideData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="DataRegistry")
	TSubclassOf<UFortDataRegistrySource_ScopedCurveTable> CreatedSourceClass;

	UPROPERTY(Transient)
	TArray<FFortOverrideData_CurveTableEntry> OverrideCurveTableDataArray;

};

UCLASS(BlueprintType)
class UFortMetaDataRegistrySource_OverrideDataTable : public UFortMetaDataRegistrySource_OverrideData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="DataRegistry")
	TSubclassOf<UFortDataRegistrySource_ScopedDataTable> CreatedSourceClass;

	UPROPERTY(VisibleAnywhere, Category="DataRegistry", meta=(DisplayThumbnail="false"))
	TObjectPtr<UObject> RowStruct;

	UPROPERTY(Transient)
	TArray<FFortOverrideData_DataTableEntry> OverrideDataTableDataArray;

};

