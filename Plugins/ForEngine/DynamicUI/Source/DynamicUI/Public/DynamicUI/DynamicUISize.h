// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "DynamicUI/DynamicUIWidgetTarget.h"
#include "DynamicUISize.generated.h"

class UDynamicUISizeBase;
class UDynamicUISizeOverrideBase;

UENUM()
enum class EDynamicUISizeMatch : int32
{
	Both = 0,
	Width = 1,
	Height = 2,
};

UCLASS(Abstract, EditInlineNew, CollapseCategories)
class UDynamicUISizeBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Dynamic UI|Override", meta=(EditCondition="bUseOverride"))
	TObjectPtr<UDynamicUISizeOverrideBase> SizeOverride;

	UPROPERTY(EditAnywhere, Category="Dynamic UI|Override", meta=(InlineEditConditionToggle))
	uint8 bUseOverride : 1;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	uint8 bUseRenderTransform : 1;

};

UCLASS(MinimalAPI, meta=(DisplayName="Fixed"))
class UDynamicUISizeFixed : public UDynamicUISizeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	FVector2f Size;

};

UCLASS(MinimalAPI, meta=(DisplayName="Match Widget"))
class UDynamicUISizeMatchWidget : public UDynamicUISizeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	FDynamicUIWidgetTarget TargetWidget;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	EDynamicUISizeMatch MatchType;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Dynamic UI", meta=(EditCondition="bUseFallbacks"))
	TArray<UDynamicUISizeBase*> Fallbacks;

	UPROPERTY(EditAnywhere, Category="Dynamic UI", meta=(InlineEditConditionToggle))
	uint8 bUseFallbacks : 1;

};

UCLASS(Abstract, EditInlineNew, CollapseCategories)
class UDynamicUISizeOverrideBase : public UObject
{
	GENERATED_BODY()

};

UCLASS(meta=(DisplayName="Platform Specific Override"))
class UDynamicUISizeOverridePlatform : public UDynamicUISizeOverrideBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Visibility")
	TMap<FName, TObjectPtr<UDynamicUISizeBase>> PlatformOverrides;

	UPROPERTY(EditAnywhere, Instanced, Category="Visibility")
	TMap<ECommonInputType, TObjectPtr<UDynamicUISizeBase>> InputTypeOverrides;

};

UCLASS(MinimalAPI, meta=(DisplayName="Scale"))
class UDynamicUISizeScale : public UDynamicUISizeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	FVector2f Scale;

};

