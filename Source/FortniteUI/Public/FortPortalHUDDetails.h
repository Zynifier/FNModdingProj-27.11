// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortActorIndicatorWidget.h"
#include "OnlineLinkId.h"
#include "FortPortalHUDDetails.generated.h"

class UAthenaMarkerPointer;
class UCommonActivatableWidgetSwitcher;
class UFortGameActivity;
class UFortInteractContextInfo;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", ClassGroup="UI"))
class UFortPortalHUDDetails : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	FORTNITEUI_API void ClearCachedWorldPos();

	UFUNCTION(BlueprintPure, meta=(BlueprintProtected))
	FORTNITEUI_API UFortInteractContextInfo* GetActiveContextInfo();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void HandleActivityQueryComplete(UFortGameActivity* QueriedActivity);

	UFUNCTION()
	FORTNITEUI_API void HandleMatchmakingComplete(bool Success);

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void QueryGameActivity(const FOnlineLinkId& LinkId);

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	FORTNITEUI_API void SetActiveContextInfo(UFortInteractContextInfo* ActiveContextInfo);

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void SetActiveMatchmakingTextIndex(int32 newIndex);

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	FORTNITEUI_API void SetCachedWorldPos(FVector InWorldPos);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPortalHUDDetails", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaMarkerPointer> MarkerPointer;

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> MobileInfo_Matchmaking_Switcher;

};

