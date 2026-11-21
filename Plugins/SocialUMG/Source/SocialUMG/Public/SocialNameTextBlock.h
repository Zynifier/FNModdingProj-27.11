// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonRichTextBlock.h"
#include "Math/Color.h"
#include "SocialTypes.h"
#include "SocialNameTextBlock.generated.h"

class USocialUser;

UCLASS(meta=(DisableNativeTick))
class SOCIALUMG_API USocialNameTextBlock : public UCommonRichTextBlock
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<USocialUser> SocialUser;

	UPROPERTY(EditAnywhere, Category="SocialNameTextBlock")
	float MinDesiredSize;

	UPROPERTY(EditAnywhere, Category="SocialNameTextBlock")
	float MaxDesiredSize;

	UPROPERTY(EditAnywhere, Category="SocialNameTextBlock")
	bool bShowSecondName;

	UPROPERTY(EditAnywhere, Category="SocialNameTextBlock")
	EPlatformIconDisplayRule PlatformIconDisplayRule;

	UPROPERTY(EditAnywhere, Category="SocialNameTextBlock", meta=(EditCondition="bShowSecondName"))
	bool bWrapToNextLine;

	UPROPERTY(EditAnywhere, Category="SocialNameTextBlock", meta=(EditCondition="bShowSecondName"))
	FColor SecondNameColor;

	UPROPERTY(EditAnywhere, Category="SocialNameTextBlock", meta=(EditCondition="bShowSecondName"))
	int32 SecondNameFontSize;

};

