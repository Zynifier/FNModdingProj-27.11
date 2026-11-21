// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Common/FortLazyImage.h"
#include "FortSocialAvatarIcon.generated.h"

class UFortSocialUser;
class UMaterialInterface;
class UTexture2D;

UCLASS()
class UFortSocialAvatarIcon : public UFortLazyImage
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RepresentLocalPlayer();

protected:
	UPROPERTY(EditAnywhere, Category="FortSocialAvatarIcon")
	TObjectPtr<UMaterialInterface> AvatarMaterial;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFortSocialUser> SocialUser;

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> AvatarTexture;

};

