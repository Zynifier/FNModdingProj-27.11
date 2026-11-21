// Copyright Epic Games, Inc. All Rights Reserved.

#include "Kinematic/KinematicMoverComponent.h"

#ifndef FORTSTUB_SKIP_THUNK_PARAMS
#define FORTSTUB_SKIP_THUNK_PARAMS
static void FortStub_SkipThunkParams(FFrame& Stack, UFunction* Function)
{
	if (Function)
	{
		for (TFieldIterator<FProperty> It(Function); It && It->HasAnyPropertyFlags(CPF_Parm); ++It)
		{
			if (It->HasAnyPropertyFlags(CPF_ReturnParm))
			{
				continue;
			}
			void* Temp = FMemory::Malloc(It->GetSize(), It->GetMinAlignment());
			It->InitializeValue(Temp);
			Stack.StepCompiledIn(Temp, It->GetClass());
			It->DestroyValue(Temp);
			FMemory::Free(Temp);
		}
	}
	P_FINISH;
}
#endif

UBaseMovementMode* UKinematicMoverComponent::FindMovementMode(TSubclassOf<UBaseMovementMode> MovementMode) const
{
	return nullptr;
}

FVector UKinematicMoverComponent::GetGravityAcceleration() const
{
	return FVector();
}

const FKinematicMoverInputCmdContext& UKinematicMoverComponent::GetLastInputCmd() const
{
	static FKinematicMoverInputCmdContext Dummy;
	return Dummy;
}

UPrimitiveComponent* UKinematicMoverComponent::GetMovementBase() const
{
	return nullptr;
}

FName UKinematicMoverComponent::GetMovementBaseBoneName() const
{
	return FName();
}

FVector UKinematicMoverComponent::GetMovementIntent() const
{
	return FVector();
}

FName UKinematicMoverComponent::GetMovementModeName() const
{
	return FName();
}

const FKinematicMoverSyncState& UKinematicMoverComponent::GetSyncState() const
{
	static FKinematicMoverSyncState Dummy;
	return Dummy;
}

FRotator UKinematicMoverComponent::GetTargetOrientation() const
{
	return FRotator();
}

FVector UKinematicMoverComponent::GetUpDirection() const
{
	return FVector();
}

FVector UKinematicMoverComponent::GetVelocity() const
{
	return FVector();
}

void UKinematicMoverComponent::HandleImpact(FMoverOnImpactParams& ImpactParams)
{
}

bool UKinematicMoverComponent::HasValidCachedInputCmd() const
{
	return false;
}

bool UKinematicMoverComponent::HasValidCachedState() const
{
	return false;
}

bool UKinematicMoverComponent::IsAirborne() const
{
	return false;
}

bool UKinematicMoverComponent::IsFalling() const
{
	return false;
}

bool UKinematicMoverComponent::IsOnGround() const
{
	return false;
}

DEFINE_FUNCTION(UKinematicMoverComponent::execK2_QueueLayeredMove)
{
	FortStub_SkipThunkParams(Stack, UKinematicMoverComponent::StaticClass()->FindFunctionByName(TEXT("K2_QueueLayeredMove")));
}
void UKinematicMoverComponent::K2_QueueLayeredMove(const int32& MoveAsRawData)
{
}

void UKinematicMoverComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UKinematicMoverComponent::PhysicsVolumeChanged(APhysicsVolume* NewVolume)
{
}

void UKinematicMoverComponent::QueueNextMode(FName DesiredModeName, bool bShouldReenter)
{
}

void UKinematicMoverComponent::SetGravityOverride(bool bOverrideGravity, FVector GravityAcceleration)
{
}

bool UKinematicMoverComponent::TryGetFloorCheckHitResult(FHitResult& OutHitResult) const
{
	return false;
}
