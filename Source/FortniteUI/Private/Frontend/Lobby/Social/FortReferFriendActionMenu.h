// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortReleaseVersion.h"
#include "SocialInteractionMenu.h"
#include "FortReferFriendActionMenu.generated.h"

class UCommonButtonBase;
enum class EReferFriendOrigin : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortReferFriendActionMenu : public USocialActionMenu
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRequestOriginChanged(EReferFriendOrigin RequestOrigin);

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, DuplicateTransient, Category="ReleaseVersion")
	FFortReleaseVersion FortReleaseVersion;
#endif

private:
	UPROPERTY(Export, meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Hide;

};

