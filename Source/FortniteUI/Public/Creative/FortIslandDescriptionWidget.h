// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortIslandDescriptionWidget.generated.h"

class UCommonListView;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortIslandDescriptionWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDescriptionChanged(bool bIsEmptyDescription);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortIslandDescriptionWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_IslandDescriptionLines;

};

