#include "ActorUtilityPluginPrivatePCH.h"
#include "AUP_FunctionLibrary.h"

UActorComponent* UActorUtilityFunctionLibrary::AttachComponentOfClass(UObject* WorldContextObject, TSubclassOf<UActorComponent> ComponentClass, AActor* Owner, FName ComponentName, USceneComponent* AttachTo, FName SocketName)
{
	if (!Owner)
	{
		return nullptr;
	}

	UActorComponent* Component = NewObject<UActorComponent>(Owner, *ComponentClass, ComponentName);
	if (!Component)
	{
		return nullptr;
	}

	Component->RegisterComponent();

	USceneComponent* SceneComponent = Cast<USceneComponent>(Component);
	if (SceneComponent)
	{
		SceneComponent->SetWorldLocation(Owner->GetActorLocation());
		SceneComponent->SetWorldRotation(Owner->GetActorRotation());

		USceneComponent* AttachToComponent = AttachTo ? AttachTo : Owner->GetRootComponent();

		SceneComponent->AttachToComponent(AttachToComponent, FAttachmentTransformRules::KeepWorldTransform, SocketName);
	}

	return Component;
}