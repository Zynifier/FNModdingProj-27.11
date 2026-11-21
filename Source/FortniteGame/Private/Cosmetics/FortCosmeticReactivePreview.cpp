// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/FortCosmeticReactivePreview.h"

void AFortCosmeticReactivePreview::DispatchReactEnd()
{
}

void AFortCosmeticReactivePreview::DispatchReactStart()
{
}

const FCosmeticVariantInfo& AFortCosmeticReactivePreview::GetVariantInfo() const
{
	static FCosmeticVariantInfo Dummy;
	return Dummy;
}

void AFortCosmeticReactivePreview::OnBoundingActorEndedPlay(AActor* ActorEndingPlay, EEndPlayReason::Type Reason)
{
}

void AFortCosmeticReactivePreview::OnFortPlayerPawnFinishedCustomization(AFortPlayerPawn* Pawn)
{
}

void AFortCosmeticReactivePreview::StartSmoothDynamicStat(UObject* Requester, float From, float To, float AtRate, EFCRP_LoopBehavior EndBehavior)
{
}

void AFortCosmeticReactivePreview::StartSteppedDynamicStat(UObject* Requester, int32 From, int32 To, int32 AtRate, EFCRP_LoopBehavior EndBehavior)
{
}
