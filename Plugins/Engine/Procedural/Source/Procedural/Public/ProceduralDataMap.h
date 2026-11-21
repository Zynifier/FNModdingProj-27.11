// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Curves/CurveLinearColor.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralDataMap.generated.h"

USTRUCT(BlueprintType)
struct FProceduralRemapFloatCurve
{
	GENERATED_BODY()

public:
	/** Optional curve used to remap values. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mapping", meta=(XAxisName="Data Value", YAxisName="Remapped Value"))
	FRuntimeFloatCurve RemapCurve;

};

USTRUCT(BlueprintType)
struct FProceduralRemapVectorCurve
{
	GENERATED_BODY()

public:
	/** Optional curve used to remap texture values (ignored for rotation maps). */
	UPROPERTY(EditAnywhere, Category="Mapping", meta=(AlwaysDisplayColorCurves="true", AlwaysHideGradientEditor="true", XAxisName="Data Value", YAxisName="Remapped Value"))
	FRuntimeCurveLinearColor RemapCurve;

};

UCLASS(Abstract, EditInlineNew, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object"), AutoExpandCategories=("DataMapping"))
class UProceduralDataMap : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Mapping", meta=(InlineEditConditionToggle))
	bool bUseRemapCurve;

};

UCLASS(Abstract, BlueprintType, HideCategories=("Object"), AutoExpandCategories=("DataMapping"))
class UProceduralFloatDataMap : public UProceduralDataMap
{
	GENERATED_BODY()

public:
	/** Optional curve used to remap values. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mapping", meta=(EditCondition="bUseRemapCurve"))
	FProceduralRemapFloatCurve RemapCurve;

};

UCLASS(Abstract, BlueprintType, HideCategories=("Object"), AutoExpandCategories=("DataMapping"))
class UProceduralVectorDataMap : public UProceduralDataMap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mapping", meta=(EditCondition="bUseRemapCurve"))
	FProceduralRemapVectorCurve RemapCurve;

};

