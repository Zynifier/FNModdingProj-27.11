// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortUIManagerWidget_NUI.h"
#include "FortUIManagerWidget_Campaign.generated.h"

class UFortUINavigationManager;
class UObject;
class UTalkingHead;

UCLASS()
class FORTNITEUI_API UFortUIManagerWidget_Campaign : public UFortUIManagerWidget_NUI
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UI Manager", meta=(WorldContext="WorldContextObject"))
	void ForceInvalidUIStateUntilNextCinematic();

	UFUNCTION(BlueprintPure, Category="UI Manager|Navigation")
	UFortUINavigationManager* GetNavigationManager() const;

	UFUNCTION(BlueprintCallable, Category="UI Manager", meta=(WorldContext="WorldContextObject"))
	static UFortUINavigationManager* GetUINavigationManager(UObject* WorldContextObject);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortUINavigationManager> NavigationManager;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTalkingHead> TalkingHead;

};

