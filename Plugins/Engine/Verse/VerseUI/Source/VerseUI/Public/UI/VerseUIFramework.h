// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIFWidget.h"
#include "UObject/NoExportTypes.h"
#include "Player/EntityActorPlayerComponent.h"
#include "VerseUIFramework.generated.h"

class UUIFrameworkPlayerComponent;
class UUIFrameworkWidget;

UCLASS(Abstract)
class VERSEUI_API UVersePlayerUIEntityComponent : public UEntityActorPlayerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUIFrameworkPlayerComponent> UIFComponent;

};

UCLASS(Abstract)
class VERSEUI_API UVerseWidgetNativeBase : public UObject, public IUIFrameworkWidgetWrapperInterface
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UUIFrameworkWidget> UIFWidgetInstance;

};

