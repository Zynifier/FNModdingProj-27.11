// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortBattlePassLevelCount.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassLevelCount : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortBattlePassLevelCount(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_LevelCount;

};

