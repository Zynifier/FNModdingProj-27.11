// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortPresenceUserListEntry.h"
#include "FortSocialUserListEntry.generated.h"

class UImage;
class USidebarSocialTagListBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSocialUserListEntry : public UFortPresenceUserListEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Lock;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialUserListEntry", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<USidebarSocialTagListBase> SocialTagList;

};

