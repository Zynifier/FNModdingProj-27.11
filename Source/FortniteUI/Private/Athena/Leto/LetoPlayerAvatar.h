// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "LetoPlayerAvatar.generated.h"

class UFortSocialAvatarIcon;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class ULetoPlayerAvatar : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> AvatarIcon;

};

