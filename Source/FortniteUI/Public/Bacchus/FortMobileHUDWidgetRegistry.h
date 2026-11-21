// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/LayoutProfile/FortMobileHUDContextModel.h"
#include "UI/Bacchus/FortMobileHUDWidgetRegistryBase.h"
#include "FortMobileHUDWidgetRegistry.generated.h"

class UFortMobileHUDContextModel;
class UFortMobileHUDElement;
class UFortMobileHUDElementProxy;
class UFortMobileHUDWidgetBehaviorExtension;
class UFortMobileHUDWidgetCustomPropertyModel;
class UHUDLayoutToolV2_WidgetPreview;
class UHUDWidgetBehavior;

USTRUCT()
struct FHUDWidgetBehaviorExtensionsRegistryEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HUDWidgetBehaviorExtensionsRegistryEntry")
	FGameplayTag HUDWidgetBehaviorTag;

	UPROPERTY(EditAnywhere, Category="HUDWidgetBehaviorExtensionsRegistryEntry")
	TArray<TSubclassOf<UFortMobileHUDWidgetBehaviorExtension>> HUDWidgetBehaviorExtensions;

};

USTRUCT()
struct FHUDWidgetBehaviorRegistryEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HUDWidgetBehaviorRegistryEntry", meta=(Categories="MobileHUD"))
	FGameplayTag HUDWidgetBehaviorTag;

	UPROPERTY(EditAnywhere, Category="HUDWidgetBehaviorRegistryEntry", meta=(Categories="MobileHUD"))
	FGameplayTag HUDWidgetOverrideTag;

	UPROPERTY(EditAnywhere, Category="HUDWidgetBehaviorRegistryEntry")
	TSubclassOf<UHUDWidgetBehavior> HUDWidgetBehaviorClass;

};

USTRUCT()
struct FHUDWidgetException
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HUDWidgetException", meta=(Categories="MobileHUD"))
	FHUDWidgetBehaviorRegistryEntry HUDWidgetBehaviorRegistryEntry;

	UPROPERTY(EditAnywhere, Category="HUDWidgetException")
	FString CVarEnabler;

};

USTRUCT()
struct FHUDWidgetRegistryEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HUDWidgetRegistryEntry", meta=(Categories="MobileHUD"))
	FGameplayTag HUDWidgetTag;

	UPROPERTY(EditAnywhere, Category="HUDWidgetRegistryEntry")
	bool bIsMandatory;

	UPROPERTY(EditAnywhere, Category="HUDWidgetRegistryEntry", meta=(ClampMax="1", ClampMin="0"))
	float MandatoryOnScreenPercent;

	UPROPERTY(EditAnywhere, Category="HUDWidgetRegistryEntry")
	int32 MaximumAmountOfInstances;

	UPROPERTY(EditAnywhere, Category="HUDWidgetRegistryEntry")
	int32 ZOrder;

	UPROPERTY(EditAnywhere, Category="HUDWidgetRegistryEntry", meta=(InlineEditConditionToggle))
	bool bHasDynamicUIUniqueID;

	UPROPERTY(EditDefaultsOnly, Category="HUDWidgetRegistryEntry", meta=(DisplayAfter="MaximumAmountOfInstances", EditCondition="bHasDynamicUIUniqueID"))
	FName DynamicUIUniqueID;

	UPROPERTY(EditAnywhere, Category="HUDWidgetRegistryEntry")
	TSubclassOf<UFortMobileHUDElement> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category="HUDWidgetRegistryEntry")
	TSubclassOf<UFortMobileHUDElementProxy> HUDWidgetProxyClass;

	UPROPERTY(EditAnywhere, Category="HUDWidgetRegistryEntry")
	TSubclassOf<UHUDLayoutToolV2_WidgetPreview> HUDWidgetPreviewClass;

	UPROPERTY(EditAnywhere, Instanced, Category="HUDWidgetRegistryEntry")
	TArray<TObjectPtr<UFortMobileHUDWidgetCustomPropertyModel>> CustomPropertyModels;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Instanced, Category="HUDWidgetRegistryEntry")
	TArray<TObjectPtr<UFortMobileHUDWidgetCustomPropertyModel>> EditorCustomPropertyModels;
#endif

};

USTRUCT()
struct FHUDWidgetSchemaInitializer
{
	GENERATED_BODY()

};

UCLASS()
class UFortMobileHUDWidgetRegistry : public UFortMobileHUDWidgetRegistryBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Registry", meta=(AllowAbstract="false", TitleProperty="HUDWidgetBehaviorTag"))
	TArray<FHUDWidgetBehaviorRegistryEntry> HUDWidgetBehaviorRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Registry", meta=(AllowAbstract="false", DisplayName="HUD Widget Registry", TitleProperty="HUDWidgetTag"))
	TArray<FHUDWidgetRegistryEntry> HUDWidgetRegistry;

	UPROPERTY(EditDefaultsOnly, Category="ContextLayouts")
	TArray<TObjectPtr<UFortMobileHUDContextModel>> ContextLayoutModels;

	UPROPERTY(EditDefaultsOnly, Category="Extensions")
	TArray<FFortMobileHUDContextModelExtension> ContextLayoutModelExtensions;

	UPROPERTY(EditDefaultsOnly, Category="Extensions")
	TArray<FHUDWidgetBehaviorExtensionsRegistryEntry> HUDWidgetBehaviorExtensions;

	UPROPERTY(EditDefaultsOnly, Category="Expetion")
	TArray<FHUDWidgetException> HUDWidgetExceptions;

	UPROPERTY(EditDefaultsOnly, Category="Registry Builder")
	bool bIsRegistryUsedInHUDLayoutTool;

};

