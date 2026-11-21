// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "Plugin/Squeegee/FortSqueegeeTypes.h"
#include "SqueegeeUIGameFeatureAction.generated.h"

class UFortContentGatingIntroModal;
class UUserWidget;

USTRUCT()
struct FSqueegeeInjectionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SqueegeeInjectionData")
	ESqueegeeWidgetInjection WidgetType;

	UPROPERTY(EditAnywhere, Category="SqueegeeInjectionData")
	TSoftClassPtr<UUserWidget> WidgetClass;

};

USTRUCT()
struct FSqueegeeTextData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SqueegeeTextData")
	ESqueegeeText TextType;

	UPROPERTY(EditAnywhere, Category="SqueegeeTextData")
	FText DesiredText;

};

UCLASS(MinimalAPI, meta=(DisplayName="Set up Squeegee Data"))
class USqueegeeUIGameFeatureAction : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="SqueegeeUIGameFeatureAction")
	TArray<FSqueegeeInjectionData> SqueegeeWidgetInjections;

	UPROPERTY(EditAnywhere, Category="SqueegeeUIGameFeatureAction")
	TArray<FSqueegeeTextData> SqueegeTexts;

	UPROPERTY(EditAnywhere, Category="SqueegeeUIGameFeatureAction")
	TSoftClassPtr<UFortContentGatingIntroModal> SqueegeeIntroModalClass;

};

