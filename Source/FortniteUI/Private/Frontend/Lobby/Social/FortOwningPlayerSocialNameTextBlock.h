// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortOwningPlayerSocialNameTextBlock.generated.h"

class USocialNameTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortOwningPlayerSocialNameTextBlock : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortOwningPlayerSocialNameTextBlock(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USocialNameTextBlock> Text_SocialName;

};

