// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortBattlePassResourceCounter.generated.h"

class UCommonTextBlock;
class UFortLazyImage;
class UFortPersistentResourceItemDefinition;

UCLASS(meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassResourceCounter : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassResourceCounter", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ResourceName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassResourceCounter", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_ResourceIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassResourceCounter", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ResourceCount;

	UPROPERTY(Transient)
	TObjectPtr<UFortPersistentResourceItemDefinition> CurrentResource;

};

