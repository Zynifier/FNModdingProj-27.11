// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DynamicUI/DynamicUITypes.h"
#include "DynamicUIAllow.generated.h"

class UCommonInputActionDomain;
class UDynamicUIConstraintBase;
class UDynamicUISizeBase;
class UWidget;

USTRUCT()
struct FDynamicUIAllowed
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(AllowAbstract="false"))
	TSoftClassPtr<UWidget> Widget;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	EDynamicUIZOrder ZOrder;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(EditCondition="ZOrder == EDynamicUIZOrder::Custom"))
	int32 CustomZOrder;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(DisplayAfter="Widget", EditCondition="bIsUnique"))
	FName UniqueID;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI|Action Domain", meta=(EditCondition="bUseActionDomain"))
	TSoftObjectPtr<UCommonInputActionDomain> ActionDomain;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Dynamic UI|Layout")
	TObjectPtr<UDynamicUIConstraintBase> LayoutConstraint;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Dynamic UI|Layout")
	TObjectPtr<UDynamicUISizeBase> SizeModifier;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(EditCondition="bUseLayerOverride", GetOptions="DynamicUI.DynamicUIScene.GetLayerNames"))
	FString LayerOverride;
#endif

	UPROPERTY()
	uint8 LayerIDOverride;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(InlineEditConditionToggle))
	uint8 bIsUnique : 1;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(InlineEditConditionToggle))
	uint8 bUseActionDomain : 1;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(InlineEditConditionToggle))
	uint8 bUseLayerOverride : 1;

};

