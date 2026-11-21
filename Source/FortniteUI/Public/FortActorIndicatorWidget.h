// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortHUDElementWidget.h"
#include "UI/FortActorIndicatorInterface.h"
#include "UI/FortElevationData.h"
#include "FortActorIndicatorWidget.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI", ClassGroup="UI", DisableNativeTick))
class FORTNITEUI_API UFortActorIndicatorWidget : public UFortHUDElementWidget, public IFortActorIndicatorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void Deinit();

	UFUNCTION(BlueprintCallable)
	virtual void Init(AActor* TargetedActor);

	UFUNCTION(BlueprintPure)
	bool IsIndicatingActor(const AActor* OtherActor) const;

	UFUNCTION(BlueprintCallable)
	virtual void SetIndicatedActor(AActor* NewIndicatorActor);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTargetActorChanged(AActor* TargetedActor);

	UPROPERTY(Transient)
	TObjectPtr<AActor> IndicatedActor;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="ActorIndicator", meta=(BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UPrimitiveComponent> IndicatedActorComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	FVector RelativeLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	float MaxDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	bool bClampOnScreen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	bool bShowClampToScreenArrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	FElevationArrowData ElevationArrowData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	bool bUseScreenSpacePosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	FVector2D ScreenSpaceRelativeOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	int32 ScreenPriority;

};

