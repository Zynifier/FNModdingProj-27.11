// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanelSlot.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "FortMobileHUDLayoutProfileSaveTypes.generated.h"

UENUM()
enum class ESchemaModificationType : uint8
{
	AddOrModify = 0,
	Remove = 1,
	Count = 2,
};

USTRUCT()
struct FFortMobileHUDWidgetCustomPropertySave
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertySave")
	FGameplayTag PropertyTag;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertySave")
	FString PropertyValue;

};

USTRUCT()
struct FFortMobileHUDWidgetLayoutSave
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetLayoutSave")
	FAnchorData LayoutData;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetLayoutSave")
	TArray<FFortMobileHUDWidgetCustomPropertySave> CustomProperties;

};

USTRUCT()
struct FFortMobileHUDWidgetSchemaSave
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetSchemaSave")
	FGameplayTag HUDWidgetClassTag;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetSchemaSave")
	FGameplayTag BehaviorClassTag;

	UPROPERTY(VisibleAnywhere, Category="FortMobileHUDWidgetSchemaSave")
	FGuid Guid;

	UPROPERTY()
	FFortMobileHUDWidgetLayoutSave HUDWidgetLayout;

};

USTRUCT()
struct FFortMobileHUDContextLayoutSave
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDContextLayoutSave")
	FGameplayTag ContextLayoutTag;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDContextLayoutSave")
	TArray<FFortMobileHUDWidgetSchemaSave> HUDWidgetSchemas;

};

USTRUCT()
struct FFortMobileHUDLayoutProfileSave
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutProfileSave")
	FText ProfileName;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDLayoutProfileSave")
	TArray<FFortMobileHUDContextLayoutSave> ContextLayouts;

};

USTRUCT()
struct FFortMobileSchemaModification
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortMobileSchemaModification")
	FGuid Guid;

	UPROPERTY(EditAnywhere, Category="FortMobileSchemaModification")
	ESchemaModificationType ModificationType;

	UPROPERTY(EditAnywhere, Category="FortMobileSchemaModification")
	FGameplayTag OwningContextTag;

	UPROPERTY(EditAnywhere, Category="FortMobileSchemaModification")
	FFortMobileHUDWidgetSchemaSave ModifiedSchema;

};

USTRUCT()
struct FFortMobileSchemaModificationContainer
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileSchemaModificationContainer")
	TArray<FFortMobileSchemaModification> Modifications;

};

