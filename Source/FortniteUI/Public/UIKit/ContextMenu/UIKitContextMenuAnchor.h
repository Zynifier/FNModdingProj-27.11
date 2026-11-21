// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "UIKitContextMenuAnchor.generated.h"

class UMenuAnchor;
class UUserWidget;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UUIKitContextMenuAnchor : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Menu Spawned"))
	void BP_OnMenuSpawned(UUserWidget* Widget);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="UIKitContextMenuAnchor", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> Anchor;

	UPROPERTY(EditAnywhere, Category="UIKitContextMenuAnchor")
	TSubclassOf<UUserWidget> MenuWidgetClass;

private:
	UFUNCTION()
	UUserWidget* HandleGetUserMenuContent();

};

