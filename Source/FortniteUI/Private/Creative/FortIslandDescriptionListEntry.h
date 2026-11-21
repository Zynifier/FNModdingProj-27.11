// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "UObject/NoExportTypes.h"
#include "FortIslandDescriptionListEntry.generated.h"

class UCommonTextBlock;

UCLASS()
class UFortIslandDescriptionLineData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText IslandDescriptionLine;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortIslandDescriptionListEntry : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortIslandDescriptionListEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_IslandDescriptionLine;

};

